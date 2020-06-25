// -*- C++ -*-
/*!
 * @file  AnalogToPercentConverterTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "AnalogToPercentConverterTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* analogtopercentconverter_spec[] =
  {
    "implementation_id", "AnalogToPercentConverterTest",
    "type_name",         "AnalogToPercentConverterTest",
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
AnalogToPercentConverterTest::AnalogToPercentConverterTest(RTC::Manager* manager)
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
AnalogToPercentConverterTest::~AnalogToPercentConverterTest()
{
}



RTC::ReturnCode_t AnalogToPercentConverterTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("percent", m_percentIn);
  
  // Set OutPort buffer
  addOutPort("analogData", m_analogDataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("analogMaxVal", m_analogMaxVal, "700");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t AnalogToPercentConverterTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t AnalogToPercentConverterTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t AnalogToPercentConverterTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t AnalogToPercentConverterTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void AnalogToPercentConverterTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(analogtopercentconverter_spec);
    manager->registerFactory(profile,
                             RTC::Create<AnalogToPercentConverterTest>,
                             RTC::Delete<AnalogToPercentConverterTest>);
  }
  
};


