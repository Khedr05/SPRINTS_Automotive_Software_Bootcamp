SET PATH=C:\Keil_v5\ARM\ARMCLANG\Bin;C:\WinAVR-20100110\bin;C:\WinAVR-20100110\utils\bin;C:\Program Files\Common Files\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files\dotnet\;C:\Program Files\Git\cmd;C:\MinGW\bin;C:\yagarto-20121222\bin;C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\;C:\Program Files (x86)\qemu\;;C:\Program Files\Microchip\xc8\v2.41\bin;C;D:\Programing\Embedded System Diploma\Embedded System Ide\bin;C:\Program Files\PuTTY\;C:\Program Files (x86)\dotnet\;C:\Users\20101\AppData\Local\Microsoft\WindowsApps;C:\MinGW\bin;C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\;C:\Program Files (x86)\qemu\;D:\Programing\Es_Program_setup\Microsoft VS Code\bin;C:\ProgramData\20101\gitkraken\bin
SET CPU_TYPE=TM4C123GH6PM
SET CPU_VENDOR=Texas Instruments
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\dio_prog.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\dio_config.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\main.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\led_prog.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\led_config.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\push_btn_prog.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\push_btn_config.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\app.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\systick_prog.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\systick_config.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\startup_tm4c123._ac"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmClang.exe" @".\objects\system_tm4c123.__i"
"C:\Keil_v5\ARM\ARMCLANG\Bin\ArmLink" --Via ".\Objects\dio.lnp"
"C:\Keil_v5\ARM\ARMCLANG\Bin\fromelf.exe" ".\Objects\dio.axf" --i32combined --output ".\Objects\dio.hex"
