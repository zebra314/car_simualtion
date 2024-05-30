FROM ros:noetic

# Specify terminal color
ENV TERM xterm-256color

# Install nvim
RUN apt-get update && apt-get install -y neovim

# Install zsh
RUN apt-get update && apt-get install -y zsh
RUN chsh -s $(which zsh)

# Install oh-my-zsh
RUN apt-get update && apt-get install -y curl
RUN apt-get update && apt-get install -y git
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Install p10k
RUN git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
RUN sed -i 's/ZSH_THEME="robbyrussell"/ZSH_THEME="powerlevel10k\/powerlevel10k"/g' ~/.zshrc
COPY dotfiles/.p10k.zsh /root/.p10k.zsh
COPY dotfiles/.zshrc /root/.zshrc

# Install tmux
RUN apt-get update && apt-get install -y tmux 

# Install multiple zsh plugins
# 1. zsh-autosuggestions
# 2. zsh-syntax-highlighting
RUN git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
RUN git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
RUN sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/g' ~/.zshrc

# Install libeigen3-dev
RUN apt-get update && apt-get install -y libeigen3-dev

# Install qt5-default
RUN apt-get update && apt-get install -y qt5-default

# Install ROS packages  
RUN apt-get update && apt-get install -y ros-noetic-tf2-*
RUN apt-get update && apt-get install -y ros-noetic-controller-manager
RUN apt-get update && apt-get install -y ros-noetic-transmission-interface
RUN apt-get update && apt-get install -y ros-noetic-image-geometry
RUN apt-get update && apt-get install -y libcv-bridge-dev
RUN apt-get update && apt-get install -y python3-cv-bridge  
RUN apt-get update && apt-get install -y ros-noetic-cv-bridge
RUN apt-get update && apt-get install -y ros-noetic-image-transport
RUN apt-get update && apt-get install -y ros-noetic-laser-geometry
RUN apt-get update && apt-get install -y ros-noetic-rviz
RUN apt-get update && apt-get install -y ros-noetic-velocity-controllers
RUN apt-get update && apt-get install -y ros-noetic-joint-state-controller
RUN apt-get update && apt-get install -y ros-noetic-joint-state-publisher
RUN apt-get update && apt-get install -y ros-noetic-joint-state-publisher-gui
RUN apt-get update && apt-get install -y ros-noetic-laser-assembler
RUN apt-get update && apt-get install -y ros-noetic-gazebo-ros-pkgs
# RUN apt-get update && apt-get install -y ros-noetic-gazebo-ros
RUN apt-get update && apt-get install -y ros-noetic-gazebo-ros-control
RUN apt-get update && apt-get install -y ros-noetic-gmapping
RUN apt-get update && apt-get install -y ros-noetic-map-server
RUN apt-get update && apt-get install -y ros-noetic-navigation
RUN apt-get update && apt-get install -y ros-noetic-joy
RUN apt-get update && apt-get install -y ros-noetic-teleop-twist-joy
RUN apt-get update && apt-get install -y ros-noetic-teleop-twist-keyboard
RUN apt-get update && apt-get install -y ros-noetic-amcl
RUN apt-get update && apt-get install -y ros-noetic-move-base
RUN apt-get update && apt-get install -y ros-noetic-map-server
RUN apt-get update && apt-get install -y ros-noetic-rosbridge-server
RUN apt-get update && apt-get install -y ros-noetic-robot-state-publisher
RUN apt-get update && apt-get install -y ros-noetic-xacro 

RUN apt-get install -y python3-pip
RUN pip install qrcode_terminal tornado

# Install gazebo
COPY scripts/gazebo.sh /root/scripts/gazebo.sh
RUN chmod +x /root/scripts/gazebo.sh
RUN cd /root && /root/scripts/gazebo.sh

# Allow to run GUI
RUN apt-get update && apt-get install -y libpci-dev
RUN apt-get update && apt-get install -y x11-apps
RUN apt-get update && apt-get install -y qtwayland5
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -yqq xserver-xorg
RUN apt-get update && apt-get install -y xwayland

# Set workdir
WORKDIR /root/pollo_ws

# Entry point
COPY scripts/entrypoint.sh /root/scripts/entrypoint.sh
ENTRYPOINT ["/root/scripts/entrypoint.sh"]
CMD ["zsh"]