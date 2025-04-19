# Royal Kludge R65 US QWERTY Firmware for Croatian QWERTZ PCs

Custom QMK firmware for the Royal Kludge R65 (wired ANSI version) to enable US QWERTY output on PCs with a Croatian QWERTZ layout, without changing system settings. Includes a "Regular" mode for standard Croatian output and support for Croatian special characters (Š, Đ, Ž, Č, Ć).

It is highly likely to work with Bosnian, Serbian (Latin), and Slovenian layouts since they share the same layout, but no testing was done.

Based on the VIA keymap from the [firmware by @irfanjmdn](https://github.com/irfanjmdn/r65).

**Author**: Ljupko Kolak

## Features
- **Plug N Play Layer (PNP)**: Outputs US QWERTY characters on a Croatian QWERTZ PC.
- **Regular Layer**: Outputs standard Croatian QWERTZ characters.
- **Croatian Special Characters**: Access Š, Đ, Ž, Č, Ć via FN + S, D, Z, X, C in PNP mode.
- **Layer Switching**: Press FN + the rotary encoder to toggle between PNP and Regular modes.
- **LED Indicator**: Indicates PNP or Regular mode.
- Supports VIA, RGB lighting, and rotary encoder (volume +/-, mute), just like the firmware by @irfanjmdn.

## Compatibility
- **Keyboard**: Royal Kludge R65, wired ANSI version only.
- **Warning**: Do NOT flash on wireless or ISO variants, as it may brick the keyboard.
- Check your keyboard’s PID (e.g., e453 or e481). Older PIDs (e.g., 0172) may not support QMK/VIA. Check the [variants repository by @roperscrossroads](https://github.com/roperscrossroads/r65-variants) for more information.

## Installation
1. **Set Up QMK**:
   - Install [QMK MSYS](https://msys.qmk.fm/) and run `qmk setup`.
2. **Add Keymap**:
   - Download this repository.
   - Copy the `keymaps/plugnplay_hr/` folder to `qmk_firmware/keyboards/rk/r65/keymaps/`.
3. **Compile Firmware**:
   - Run `qmk compile -kb rk/r65 -km plugnplay_hr`.
   - Find the `.bin` or `.hex` file in `qmk_firmware/`.
4. **Flash Firmware**:
   - __On Windows__
      - Open [QMK Toolbox](https://github.com/qmk/qmk_toolbox).
      - Enter bootloader mode (press reset switch, Escape, or Fn+Shift+Esc).
      - Flash the `.bin` or `.hex` file.
   - __On Linux__
      - Run `qmk flash -kb rk/r65 -km plugnplay_hr`
6. **Test**:
   - The keyboard starts in PNP mode (US QWERTY output).
   - Press FN + the rotary encoder to switch to Regular mode (Croatian QWERTZ).

## Usage
- **PNP Mode (Layer 0)**: Types US QWERTY characters. Hold FN for functions or Croatian characters.
- **Regular Mode (Layer 2)**: Types Croatian QWERTZ characters. Hold FN for functions.
- **Layer Toggle**: Hold FN and press the rotary encoder to switch modes.
- **LED**: High for PNP, low for Regular.
- **VIA Support**: Customize keymaps via VIA configurator.

## Files
- `bin/rk_r65_plugnplay_hr.bin`: Precompiled firmware binary.
- `keymaps/plugnplay_hr/keymap.c`: Defines keymaps and layer logic.
- `keymaps/plugnplay_hr/layoutmap_us_to_hr.h`: Maps US QWERTY to Croatian QWERTZ keycodes.
- `keymaps/plugnplay_hr/rules.mk`: Enables VIA and encoder support.

## Credits
- Original firmware: [@sdk66](https://github.com/sdk66), [@iamdanielv](https://github.com/iamdanielv), [@irfanjmdn](https://github.com/irfanjmdn/r65).
- QMK Community for tools and documentation.

## License
[MIT License](LICENSE)

## Support
- Issues or questions? Open a GitHub issue or post on [r/RoyalKludge](https://www.reddit.com/r/RoyalKludge/).
- Contributions welcome via pull requests!
