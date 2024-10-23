# GPU Kernel Workspace Template

## System Pre-Requisites

1. Linux (Recommended Ubuntu 20.04)
2. Nvidia GPU

## System Checklist

- [ ] Print info about your Linux distribution.

```
lsb_release --all
```

- [ ] Print your Linux kernel version.

```
uname --all
```

- [ ] Print CPU architecture.

```
uname --machine
```

- [ ] Print disk storage devices.

```
sudo fdisk --list
```

## Setup CUDA Toolkit

- [ ] Print GPU driver version and CUDA version.

```
nvidia-smi
```

- [ ] Install CUDA Toolkit from the NVIDIA CUDA APT repository.

```
sudo apt-key adv --fetch-keys https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/3bf863cc.pub
sudo sh -c 'echo "deb https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/ /" > /etc/apt/sources.list.d/cuda.list'
sudo apt update
sudo apt install cuda
```

- [ ] Add CUDA Toolkit to your `PATH` and `LD_LIBRARY_PATH`.

```
# Add this to your .zshrc or .bashrc
export PATH=/usr/local/cuda-12.6/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-12.6/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
```

(Replace `12.6` with the CUDA Toolkit version that you installed.)

- [ ] Verify your CUDA Toolkit installation.

```
source ~/.zshrc
nvcc --version
```

-[] Install Python, according to [this guide](https://hackersandslackers.com/multiple-python-versions-ubuntu-20-04/)

```
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt update
sudo apt install python3.12
sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 1
sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.12 2
sudo update-alternatives --config python3
sudo apt remove --purge python3-apt
sudo apt autoclean
sudo apt install python3-apt
sudo apt-get install python3.12-distutils python3.12-dev python3.12-venv
curl -sS https://bootstrap.pypa.io/get-pip.py | python3.12
```

-[] Create Python virtual env. Use this guide to install the right PyTorch version for your CUDA version, which you can print by using `nvidia-smi`.

```
python3 -m venv .venv
source .venv/bin/activate
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu124
python3

--[In the Python REPL]--

>>> import torch
>>> torch.rand(5, 3)
...
>>> torch.cuda.is_available()
True
```

- [ ] Setup C++ toolchain.

```
sudo apt install g++10
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 9
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-10 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10

sudo apt install clangd-15
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 15

sudo apt install ccache

sudo apt install cmake
make test
```
