// -*- C++ -*-
/*!
 * @file  judgement.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "judgement.h"

// Module specification
// <rtc-template block="module_spec">
static const char* judgement_spec[] =
  {
    "implementation_id", "judgement",
    "type_name",         "judgement",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "ye-linna",
    "category",          "data",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
judgement::judgement(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_data_inIn("data_in", m_data_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
judgement::~judgement()
{
}



RTC::ReturnCode_t judgement::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("data_in", m_data_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t judgement::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t judgement::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t judgement::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t judgement::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t judgement::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t judgement::onExecute(RTC::UniqueId ec_id)
{
    if (m_data_inIn.isNew()) {
        m_data_inIn.read();

        double x = m_data_in.data.position.x;
             
            if (x >= 1) {
                std::cout << "A Win" << std::endl;
                std::string str;
                std::cin >> str;
            }
            else if (x <= -1) {
                std::cout << "B Win" << std::endl;
                std::string str;
                std::cin >> str;
            }
    }
  return RTC::RTC_OK;
}




/*
RTC::ReturnCode_t judgement::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t judgement::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t judgement::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t judgement::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t judgement::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void judgementInit(RTC::Manager* manager)
  {
    coil::Properties profile(judgement_spec);
    manager->registerFactory(profile,
                             RTC::Create<judgement>,
                             RTC::Delete<judgement>);
  }
  
};


