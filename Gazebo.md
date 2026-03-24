# Gazebo Simulation

**Author:** Timo Trummer 

---

## 1. Gazebo Sim

The Flix drone simulator is based on Gazebo 11 and runs the firmware code in virtual physical environment.

We would recommend building the simuation on Ubuntu 20.04, because of the avalable documentation and simple installation.

It is possible to control the simulation with either a USB remote control, or with the QGroundcontrol App.

---

## 2. Installation 

1. Clone the Flix repository using it:

Downloads the Flix project from GitHub to your computer.
```bash
git clone https://github.com/okalachev/flix.git && cd flix
```

2. Install Arduino CLI:

The Arduino CLI (Command Line Interface) allows compiling and uploading Arduino code without the graphical IDE.
```bash
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=~/.local/bin sh
```

3. Install Gazebo11
```bash
sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
sudo apt-get update
sudo apt-get install -y gazebo11 libgazebo11-dev
```
Set up your Gazebo environment variables:
```bash
echo "source /usr/share/gazebo/setup.sh" >> ~/.bashrc
source ~/.bashrc
```

4. Install SDL2 and other dependencies:

libsdl2-dev provides libraries for graphics, audio, and input handling.
```bash
sudo apt-get update && sudo apt-get install build-essential libsdl2-dev
```

5. Add your user to the input group to enable joystick support (you need to re-login after this command):

Adds your user to the input group so the simulator can access joystick input devices.
```bash
sudo usermod -a -G input $USER
```

6. Run the simulation
```bash
make simulator
```

---

## 3. Usage

Just like the real drone, the simulator can be controlled using a USB remote control or a smartphone.

### Control with smartphone
1. Install QGroundControl mobile app on your smartphone. For iOS, use QGroundControl build from TAJISOFT.
2. Connect your smartphone to the same Wi-Fi network as the machine running the simulator.
3. If you're using a virtual machine, make sure that its network is set to the bridged mode with Wi-Fi adapter selected.
4. Run the simulation.
5. Open QGroundControl app. It should connect and begin showing the virtual drone's telemetry automatically.
6. Go to the settings and enable Virtual Joystick. Auto-Center Throttle setting should be disabled.
7. Use the virtual joystick to fly the drone!

