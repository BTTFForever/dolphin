Dolphin VR
(Unofficial Dolphin build with Oculus Rift support.)
Open Source licence: GPL v2

The official Dolphin website: https://dolphin-emu.org
See the website for non-VR related help, and the Wiki for game specific information.
Don't both the official Dolphin devs with VR questions or issues, they don't know.

The VR branch: https://github.com/CarlKenner/dolphin/tree/VR
Disscusion of the VR branch: https://developer.oculusvr.com/forums/

How to run:

Optional: Copy sixense_x64.dll, iweardrv.dll, and iwrstdrv.dll into your Dolphin directory.

Oculus Rift DK1 to DK2 are supported. You need the Oculus 0.4.0 runtime installed.
Set the Rift Display Mode to "Extend Desktop to the HMD", or it won't work!
Plug the Rift in, and make sure the service is running, before launching Dolphin.

Only the OpenGL renderer will work. In Graphics, turn off Render To Main Window.
In the Graphics options Enhancements tab set the internal resolution to a multiple
of the native. 1x Native is much too blurry, I use 2.5x Native for my DK1.
Lower resoultions are faster but blurrier.
I haven't tested Anti-Aliasing or Anisotropic filtering, so use at own risk!
Post-Processing has no effect and is not implemented.
eXternal Frame Buffer is always disabled regardless of what you choose.
Turning Free-Look on in the Advanced tab allows you to walk around with Shift+WASD.
The OnScreen Display or debug information doesn't work in VR mode, so don't bother.

Choose a game and click the Play button to start. Then put on the Rift.
Keep the mouse over the Rift's window, and click to focus input.

Per-game Settings:
Virtual Reality needs to be the correct scale, and the 2D elements need to be at
the correct depth. It's different for every game.
You can edit the per-game settings by right clicking a game in the list and
choosing "properties". It doesn't take effect until you restart the game. 
You can also adjust the settings with the keyboard during the game.

Free-Look Keys:
(Free-Look must be turned on. These keys often conflict with game controls,
so you may need to map your game controls to other keys or gamepad.)
Shift+WASD to move around. If movement is too slow, the scale is too large.
Shift+Q move down, Shift+E move up.
Shift+R reset free-look position, also resets Rift position.
Shift+9 or Shift+0 halve or double speed. But fix the scale first instead.

VR 3D Settings Keys:
(Only affects scenes with some 3D perspective elements.)
Shift+R to recenter Rift.
Shift+- and Shift+= to adjust the scale to make the world smaller or bigger!
(Scale is important for VR, so try to get it life-size. Make it smaller first 
until it is toy size, then bigger until it is life-size. Move the camera closer
with Free-Look so you can see close-up to a person.)
Shift+. and Shift+/ to move the HUD closer or further and change its size.
Shift+[ and Shift+] to make the HUD thinner or thicker.
Shift+P and Shift+; to move the camera closer or further from the action.
(Permanent per-game setting, not like Free-look. Also adjusts the HUD size
to compensate for new camera position so aiming is right at Aim-Distance.
Aim distance must be set in game properties.)
Shift+O and Shift+L to tilt the camera up or down by 5 degrees.
(Correct pitch is also important for VR, you want the floor horizontal.
But most third person games angle the camera down at various angles depending on
what is happening in the game. Tilting tha camera up 10 degrees is usually a 
good compromise.)
Esc to stop emulation and give you the option to save VR settings.

VR 2D Settings:
(Only affects scenes which have no perspective projection and only 2D elements.)
Shift+I and Shift+K to tilt the 2D camera up or down by 5 degrees.
(This is good for top-down or 2.5D menus, intros, or games, for realism.)
Shift+U and Shift+J to move 2D screen out or in by 10cm, without changing size.
(I recommend less than 4 metres away so you can still feel its depth.)
Shift+M and Shift+, to scale 2D screen smaller or bigger.
(It looks like the screen is moving closer or further, but it isn't!
Stereoscopic depth isn't changing, just the size. I use this to make the screen
life size in Virtual Console games. Use Free-look to move closer to a person
to adjust the size to real-life.)
Shift+Y and Shift+H to move the 2D screen up and down by 10cm.
(Move the screen down/camera up for 2.5D games for more realism.
Move the screen up/camera down for 2D platform games to make the ground level
with the real floor. Move the screen up for top-down games so you can see better.)
You can't adjust the 2D screen thickness with the keys yet. Use the game properties.
Esc to stop emulation and give you the option to save VR settings.

VR debugging keys:
(Don't use these!)
Shift+B and Shift+N to change selected debug layer.

Other useful keys:
Alt+F5 to disconnect/reconnect virtual Wii remote.
Shift+F1 to Shift+F8 to save game with savestate 1 to 8.
(So you can exit and save and edit your settings.)
F1 to F8 to load game from savestate 1 to 8.
Esc to stop game
(It pauses to ask you to confirm stopping, so you can also use this to pause.
Take off the Rift after pressing this to view the dialog box.)
See the menus for more keys, these and other keys can be adjusted in the menus,
unlike the hardcoded Free-look and VR keys.

Razer Hydra:
You need sixense_x64.dll (not included) in your folder if you want to use the Hydra.
Exit the Razer Hydra and Sixense system tray icons before playing.

Unlike the Rift, you can plug in or unplug the Razer Hydra at any time.

This probably also supports the new Sixense STEM controller that Sixense is bringing out soon, which is likely to be backwards compatible.

This patch has no effect (dolphin behaves the same as before except for a log message) unless the user has sixense_x64.dll (part of the Sixense driver) installed (or sixense.dll for 32 bit). Users can get it from http://sixense.com/windowssdkdownload and put it in their Dolphin exe folder.

When the dll is present, and a Hydra is connected, and not sitting in the dock, and Wiimote 1 is set to Emulated Wiimote, the Hydra will automatically control Wiimote 1 and its Nuchuk or Classic Controller extensions. It will also control Gamecube controller 1 if it is enabled. While holding the hydra, the actual tilt will override any other emulated tilt, and the actual pointing will override any other emulated IR, and the actual joysticks will override other emulated joysticks, but emulated buttons, swings and shakes from other inputs will still work additively.

It currently uses a fixed control scheme to make it plug-and-play:
Wiimote:
A: right start button (middle)
B: right bumper or trigger (underneath)
Minus: right 3 button (top left)
Plus: right 4 button (top right)
Home/Recenter IR: push right stick in (top middle)
Dpad: right analog stick (top middle)
1: right 1 button (bottom left)
2: right 2 button (bottom right)
IR pointer: right controller's position in space relative to where you pressed Home
Orientation/Motion sensing: right controller's orientation/motion
Swap extension: push left stick in

Nunchuk:
C: left bumper (top) or left 1 button (bottom left)
Z: left trigger (bottom) or left 2 button (bottom right)
Stick: left stick
Orientation/Motion sensing: left controller's orientation/motion

Classic:
L: left analog trigger (bottom left unlike Classic Controller Pro)
ZL: left bumper (top left)
R: right analog trigger
ZR: right bumper
left stick: left stick
right stick: right stick
dpad: left buttons like if tilted inwards, 3=up, 2=down, 1=left, 4=right 
a, b, x, y: right buttons like if tilted inwards: 2=a, 1=b, 4=x, 3=y
minus: left start
plus: right start
home/recenter IR: push right stick in

Sideways Wiimote (if left controller is docked):
turn right hydra sideways yourself, same as above wiimote controls

Sideways Wiimote (if holding both controllers):
steering/tilt left-right: angle between controllers (like holding imaginary wheel or sideways wiimote with both hands)
tilt forwards-backwards: tilt controllers (only measures right one) forwards or backwards
motion sensing: shake or swing controllers (only measures right one)
1: right 1 button (bottom left)
2: right 2 button (bottom right)
A: left or right start button
B: left or right bumpers or triggers
minus: right 3 button (top left)
plus: right 4 button (top right)
home/recenter IR: push right stick in

GameCube:
L: left analog trigger (bottom left like GameCube controller)
Z: left or right bumper (top left or top right)
R: right analog trigger (bottom right)
analog stick: left stick
C-substick: right stick
dpad: left buttons like if tilted inwards, 3=up, 2=down, 1=left, 4=right 
a, b, x, y: right buttons like GameCube layout: 2=a, 1=b, 4=x, 3=y
start: right start

General:
Cycle between Wiimote/sideways Wiimote/Wiimote+Nunchuk/Classic: push left stick in
(note that doesn't affect the gamecube controller)
Recenter IR pointer: push right stick in (press again to get out of home screen)
Recenter hydra joysticks: dock then undock that controller
(if that doesn't help, disconnect and reconnect nunchuk/classic extension)

Troubleshooting:
Hydra isn't recognised: make sure sixense_x64.dll is in Dolphin's exe folder (see above).
Wii cursor isn't showing: push the right analog stick in, then exit the home screen.
IR Pointer doesn't aim smoothly: it uses position rather than angle, so move rather than aiming.
Orientation/motion sensing is messed up: make sure base is straight with cables at back, then dock both controllers and pick them up again. If that doesn't work, make sure you have the Sideways Wiimote setting set correctly in Wiimote settings.
Hands are swapped: The nunchuk should be the controller that says LT (or q7) on the triggers, so hold that one in your left hand.
Joystick is messed up: dock then undock both controllers, then disconnect and reconnect the extension in Wiimote settings.


## System Requirements
* OS
    * Microsoft Windows (Vista or higher).
    * Linux or Apple Mac OS X (10.7 or higher).
    * Unix-like systems other than Linux might work but are not officially supported.
* Processor
    * A CPU with SSE2 support.
    * A modern CPU (3 GHz and Dual Core, not older than 2008) is highly recommended.
* Graphics
    * A reasonably modern graphics card (Direct3D 10.0 / OpenGL 3.0).
    * A graphics card that supports Direct3D 11 / OpenGL 4.4 is recommended.

## Command line usage
(not needed for VR)
`Usage: Dolphin [-h] [-d] [-l] [-e <str>] [-b] [-V <str>] [-A <str>]`  

* -h, --help Show this help message  
* -d, --debugger Opens the debugger  
* -l, --logger Opens the logger  
* -e, --exec=<str> Loads the specified file (DOL,ELF,WAD,GCM,ISO)  
* -b, --batch Exit Dolphin with emulator  
* -V, --video_backend=<str> Specify a video backend  
* -A, --audio_emulation=<str> Low level (LLE) or high level (HLE) audio  

Available DSP emulation engines are HLE (High Level Emulation) and
LLE (Low Level Emulation). HLE is fast but often less accurate while LLE is
slow but close to perfect. Note that LLE has two submodes (Interpreter and
Recompiler), which cannot be selected from the command line.

Available video backends are "D3D" (only available on Windows Vista or higher),
"OGL". There's also "Software Renderer", which uses the CPU for rendering and
is intended for debugging purposes, only.

## Sys Files
* `totaldb.dsy`: Database of symbols (for devs only)
* `GC/font_ansi.bin`: font dumps
* `GC/font_sjis.bin`: font dumps
* `GC/dsp_coef.bin`: DSP dumps
* `GC/dsp_rom.bin`: DSP dumps

The DSP dumps included with Dolphin have been written from scratch and do not
contain any copyrighted material. They should work for most purposes, however
some games implement copy protection by checksumming the dumps. You will need
to dump the DSP files from a console and replace the default dumps if you want
to fix those issues.

## Folder structure
These folders are installed read-only and should not be changed:

* `GameSettings`: per-game default settings database
* `GC`: DSP and font dumps
* `Maps`: symbol tables (dev only)
* `Shaders`: post-processing shaders
* `Themes`: icon themes for GUI
* `Wii`: default Wii NAND contents

## User folder structure
A number of user writeable directories are created for caching purposes or for
allowing the user to edit their contents. On OS X and Linux these folders are
stored in `~/Library/Application Support/Dolphin/` and `~/.dolphin-emu`
respectively. On Windows the user directory is stored in the `My Documents`
folder by default, but there are various way to override this behavior:

* Creating a file called `portable.txt` next to the Dolphin executable will
  store the user directory in a local directory called "User" next to the
  Dolphin executable.
* If the registry string value `LocalUserConfig` exists in
  `HKEY_CURRENT_USER/Dolphin Emulator` and has the value **1**, Dolphin will
  always start in portable mode.
* If the registry string value `UserConfigPath` exists in
  `HKEY_CURRENT_USER/Dolphin Emulator`, the user folders will be stored in the
  directory given by that string. The other two methods will be prioritized
  over this setting.


List of user folders:

* `Cache`: used to cache the ISO list
* `Config`: configuration files
* `Dump`: anything dumped from dolphin
* `GameConfig`: additional settings to be applied per-game
* `GC`: memory cards
* `Load`: custom textures
* `Logs`: logs, if enabled
* `ScreenShots`: screenshots taken via Dolphin
* `StateSaves`: save states
* `Wii`: Wii NAND contents

## Custom textures
Custom textures have to be placed in the user directory under
`Load/Textures/[GameID]/`. You can find the Game ID by right-clicking a game
in the ISO list and selecting "ISO Properties".