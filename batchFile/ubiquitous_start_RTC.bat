rem start RTC
start "" "./RTC/RTnoProxy/build/src/Debug/RTnoProxyComp.exe"
start "" "./RTC/AnalogToPercentConverter/build/src/Debug/AnalogToPercentConverterComp.exe"
start "" "./RTC/SpeedTranspose/build/src/Debug/SpeedTransposeComp.exe"
start "" "./RTC/RasPiMouseSimulatorRTC/RaspberryPiMouseSimulatorComp.exe"
start "" "./RTC/judgement/build/src/Debug/judgementComp.exe"

rem RTC check
rtls -R localhost/

powershell sleep 10

rem Get host name in lower case
FOR /F %%A IN ('hostname.exe') DO SET NAME=%%A
rtcat -l localhost/%NAME%.host_cxt/RTnoProxy0.rtc
rtcat -l localhost/%NAME%.host_cxt/AnalogToPercentConverter0.rtc
rtcat -l localhost/%NAME%.host_cxt/SpeedTranspose0.rtc
rtcat -l localhost/%NAME%.host_cxt/RaspberryPiMouseSimulator0.rtc
rtcat -l localhost/%NAME%.host_cxt/judgement0.rtc

rem connect ports
rtcon localhost/%NAME%.host_cxt/RTnoProxy0.rtc:out0^
    localhost/%NAME%.host_cxt/AnalogToPercentConverter0.rtc:analogData

rtcon localhost/%NAME%.host_cxt/AnalogToPercentConverter0.rtc:percent^
    localhost/%NAME%.host_cxt/SpeedTranspose0.rtc:power1

rtcon localhost/%NAME%.host_cxt/SpeedTranspose0.rtc:speedout^
    localhost/%NAME%.host_cxt/RaspberryPiMouseSimulator0.rtc:target_velocity_in

rtcon localhost/%NAME%.host_cxt/RaspberryPiMouseSimulator0.rtc:current_pose_out^
    localhost/%NAME%.host_cxt/judgement0.rtc:data_in

pause