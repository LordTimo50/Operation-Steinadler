# Operation Steinadler - Gazebo Simulation

**Author:** Timo Trummer 

---

## 1. Gazebo Sim

The Flix drone simulator is based on Gazebo 11 and runs the firmware code in virtual physical environment.

We would recommend building the simuation on Ubuntu 20.04, because of the avalable documentation and simple installation.

It is possible to control the simulation with either a USB remote control, or with the QGroundcontrol App.

---

## 2. Installation 

1. Clone the Flix repository using it:
```bash
git clone https://github.com/okalachev/flix.git && cd flix
```

2. Install Arduino CLI:
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
```bash
sudo apt-get update && sudo apt-get install build-essential libsdl2-dev
```

5. Add your user to the input group to enable joystick support (you need to re-login after this command):
```bash
sudo usermod -a -G input $USER
```

6. Run the simulation
```bash
make simulator
```

---
