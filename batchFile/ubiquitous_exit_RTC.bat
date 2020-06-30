rem exit RTC

taskkill /IM "RTnoProxyComp.exe"
taskkill /IM "AnalogToPercentConverterComp.exe"
taskkill /IM "SpeedTransposeComp.exe"
taskkill /F /IM "RaspberryPiMouseSimulatorComp.exe"
taskkill /IM "judgementComp.exe"

pause