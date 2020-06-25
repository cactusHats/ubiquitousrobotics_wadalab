// -*- C++ -*-
/*!
 * @file  AnalogToPercentConverter.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "AnalogToPercentConverter.h"

using namespace std;

// Module specification
// <rtc-template block="module_spec">
static const char* analogtopercentconverter_spec[] =
  {
    "implementation_id", "AnalogToPercentConverter",
    "type_name",         "AnalogToPercentConverter",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.analogMaxVal", "700",

    // Widget
    "conf.__widget__.analogMaxVal", "text",
    // Constraints

    "conf.__type__.analogMaxVal", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
AnalogToPercentConverter::AnalogToPercentConverter(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_analogDataIn("analogData", m_analogData),
    m_percentOut("percent", m_percent)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
AnalogToPercentConverter::~AnalogToPercentConverter()
{
}



RTC::ReturnCode_t AnalogToPercentConverter::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("analogData", m_analogDataIn);
  
  // Set OutPort buffer
  addOutPort("percent", m_percentOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("analogMaxVal", m_analogMaxVal, "700");
  // </rtc-template>

  cout << "analogToDigitalConverter is read!" << endl;
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnalogToPercentConverter::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverter::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverter::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t AnalogToPercentConverter::onActivated(RTC::UniqueId ec_id)
{
    //アナログデータ初期化
    for (int i = 0; i < 6; i++) {
        analogData[i] = 0;
    }
    //パーセンテージ初期化
    percent = 0;
    percent_ave = 0;

    //配列初期化
    for (int i = 0; i < 20; i++) {
        data[i] = 0;
    }

  return RTC::RTC_OK;
}


RTC::ReturnCode_t AnalogToPercentConverter::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t AnalogToPercentConverter::onExecute(RTC::UniqueId ec_id)
{
    //Arduinoからのアナログデータを受信
    if (m_analogDataIn.isNew()) {
        //データの読み込み
        m_analogDataIn.read();
        //この時点で入力データがm_analogDataInに格納される
        for (int i = 0; i < m_analogData.data.length(); i++) {
            //入力データを別変数に格納
            if (i < 6) {
                analogData[i] = m_analogData.data[i];
            }
        }
        
        //最大値を超えたら修正
        if (analogData[0] > m_analogMaxVal) analogData[0] = m_analogMaxVal;

        //(A0について)0-100%に変換
        percent = double(100.0 / m_analogMaxVal) * analogData[0];

        //平滑化処理
        for (int i = 0; i < 19; i++) {
            data[19 - i] = data[19 - i - 1];
        }
        data[0] = percent;

        //配列更新
        for (int i = 0; i < 20; i++)
            percent_ave += data[i];
        percent_ave /= 20;

    }

    //次のRTCへ送信
    //m_percent.data = percent;
    m_percent.data = percent_ave;
    m_percentOut.write();

    //デバッグ出力
    if (DEBUG) {
        //cout << analogData[0] <<" " << m_analogMaxVal << endl;
        cout << "A0 = " << analogData[0] << "\tAve = " << percent_ave << "\t" << percent << "%" << endl;
    }

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnalogToPercentConverter::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverter::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverter::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverter::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverter::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void AnalogToPercentConverterInit(RTC::Manager* manager)
  {
    coil::Properties profile(analogtopercentconverter_spec);
    manager->registerFactory(profile,
                             RTC::Create<AnalogToPercentConverter>,
                             RTC::Delete<AnalogToPercentConverter>);
  }
  
};


