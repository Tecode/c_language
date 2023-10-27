## STC89C52RC + Clion + platformIo

### [解决一直卡住问题](https://github.com/platformio/platform-intel_mcs51/issues/47)

如果还是没有解决这个问题使用STC-isp下载

```shell
Building in release mode
Checking size .pio\build\STC89C52RC\firmware.hex
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
Flash: [          ]   1.3% (used 109 bytes from 8192 bytes)
Configuring upload protocol...
AVAILABLE: stcgal
CURRENT: upload_protocol = stcgal
Looking for upload port...
Auto-detected: COM3
Uploading .pio\build\STC89C52RC\firmware.hex
Cycling power: done
```

打开`/.platformio/platforms/intel_mcs51/builder/main.py`文件，找到以下代码修改参数

```python
if upload_protocol == "stcgal":
    f_cpu_khz = int(board_config.get("build.f_cpu").strip("L")) / 1000
    stcgal_protocol = board_config.get("upload.stcgal_protocol")
    env.Replace(
        UPLOADER=join(platform.get_package_dir("tool-stcgal") or "", "stcgal.py"),
        UPLOADERFLAGS=[
            "-P",
            stcgal_protocol,
            "-p",
            "$UPLOAD_PORT",
            "-t",
            int(f_cpu_khz)
            # "-a", # 注释掉这个参数
        ],
        UPLOADCMD='"$PYTHONEXE" "$UPLOADER" $UPLOADERFLAGS $SOURCE',
    )

    upload_actions = [
        env.VerboseAction(env.AutodetectUploadPort, "Looking for upload port..."),
        env.VerboseAction("$UPLOADCMD", "Uploading $SOURCE"),
    ]
```