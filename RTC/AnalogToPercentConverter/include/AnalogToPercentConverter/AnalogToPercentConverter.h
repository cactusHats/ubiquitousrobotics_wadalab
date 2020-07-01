// -*- C++ -*-
/*!
 * @file  AnalogToPercentConverter.h
 * @brief ModuleDescription
 * @date  $Date$
 *
 * $Id$
 */

#ifndef ANALOGTOPERCENTCONVERTER_H
#define ANALOGTOPERCENTCONVERTER_H

 //デバッグ用マクロ
#define DEBUG 1

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "BasicDataTypeStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class AnalogToPercentConverter
 * @brief ModuleDescription
 *
 */
class AnalogToPercentConverter
	: public RTC::DataFlowComponentBase
{
public:
	/*!
	 * @brief constructor
	 * @param manager Maneger Object
	 */
	AnalogToPercentConverter(RTC::Manager* manager);

	/*!
	 * @brief destructor
	 */
	~AnalogToPercentConverter();

	// <rtc-template block="public_attribute">

	// </rtc-template>

	// <rtc-template block="public_operation">

	// </rtc-template>

	/***
	 *
	 * The initialize action (on CREATED->ALIVE transition)
	 *
	 * @return RTC::ReturnCode_t
	 *
	 *
	 */
	virtual RTC::ReturnCode_t onInitialize();

	/***
	 *
	 * The finalize action (on ALIVE->END transition)
	 *
	 * @return RTC::ReturnCode_t
	 *
	 *
	 */
	 // virtual RTC::ReturnCode_t onFinalize();

	 /***
	  *
	  * The startup action when ExecutionContext startup
	  *
	  * @param ec_id target ExecutionContext Id
	  *
	  * @return RTC::ReturnCode_t
	  *
	  *
	  */
	  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

	  /***
	   *
	   * The shutdown action when ExecutionContext stop
	   *
	   * @param ec_id target ExecutionContext Id
	   *
	   * @return RTC::ReturnCode_t
	   *
	   *
	   */
	   // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

	   /***
		*
		* The activated action (Active state entry action)
		*
		* @param ec_id target ExecutionContext Id
		*
		* @return RTC::ReturnCode_t
		*
		*
		*/
	virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

	/***
	 *
	 * The deactivated action (Active state exit action)
	 *
	 * @param ec_id target ExecutionContext Id
	 *
	 * @return RTC::ReturnCode_t
	 *
	 *
	 */
	virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

	/***
	 *
	 * The execution action that is invoked periodically
	 *
	 * @param ec_id target ExecutionContext Id
	 *
	 * @return RTC::ReturnCode_t
	 *
	 *
	 */
	virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

	/***
	 *
	 * The aborting action when main logic error occurred.
	 *
	 * @param ec_id target ExecutionContext Id
	 *
	 * @return RTC::ReturnCode_t
	 *
	 *
	 */
	 // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

	 /***
	  *
	  * The error action in ERROR state
	  *
	  * @param ec_id target ExecutionContext Id
	  *
	  * @return RTC::ReturnCode_t
	  *
	  *
	  */
	  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

	  /***
	   *
	   * The reset action that is invoked resetting
	   *
	   * @param ec_id target ExecutionContext Id
	   *
	   * @return RTC::ReturnCode_t
	   *
	   *
	   */
	   // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);

	   /***
		*
		* The state update action that is invoked after onExecute() action
		*
		* @param ec_id target ExecutionContext Id
		*
		* @return RTC::ReturnCode_t
		*
		*
		*/
		// virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

		/***
		 *
		 * The action that is invoked when execution context's rate is changed
		 *
		 * @param ec_id target ExecutionContext Id
		 *
		 * @return RTC::ReturnCode_t
		 *
		 *
		 */
		 // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


protected:
	// <rtc-template block="protected_attribute">

	// </rtc-template>

	// <rtc-template block="protected_operation">

	// </rtc-template>

	// Configuration variable declaration
	// <rtc-template block="config_declare">
	/*!
	 * Arduinoから送られてくるアナログ値の最大値を設定．
	 * DCモータの発電量は微弱なため，最大値を調整できるようにする．
	 * （本来0-1023だが，オペアンプの関係上，現在の最大値は約730）
	 * - Name: analogMaxVal analogMaxVal
	 * - DefaultValue: 700
	 * - Unit: bit
	 * - Range: 0-730
	 */
	int m_analogMaxVal;

	// </rtc-template>

	// DataInPort declaration
	// <rtc-template block="inport_declare">
	RTC::TimedFloatSeq m_analogData;
	/*!
	 */
	RTC::InPort<RTC::TimedFloatSeq> m_analogDataIn;

	// </rtc-template>


	// DataOutPort declaration
	// <rtc-template block="outport_declare">
	RTC::TimedLong m_percent;
	/*!
	 */
	RTC::OutPort<RTC::TimedLong> m_percentOut;

	// </rtc-template>

	// CORBA Port declaration
	// <rtc-template block="corbaport_declare">

	// </rtc-template>

	// Service declaration
	// <rtc-template block="service_declare">

	// </rtc-template>

	// Consumer declaration
	// <rtc-template block="consumer_declare">

	// </rtc-template>

private:
	int analogData[6]; //Arduinoから届いたアナログデータを一時格納する変数 
	int percent; //パーセンテージ
	int data[20]; //平滑化処理で使用する配列
	int percent_ave; //平滑化後の速度データ(0-100%)

	// <rtc-template block="private_attribute">

	// </rtc-template>

	// <rtc-template block="private_operation">

	// </rtc-template>

};


extern "C"
{
	DLL_EXPORT void AnalogToPercentConverterInit(RTC::Manager* manager);
};

#endif // ANALOGTOPERCENTCONVERTER_H
