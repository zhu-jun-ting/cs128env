export PATH_TO_CS128_DIR="$(pwd)" # this should be root cs128env
echo "Path to cs128env folder: $PATH_TO_CS128_DIR"
if [[ `uname -m` == 'arm64' ]]; then
  echo "Running on native Apple Silcon"
  docker pull michaelrnowak/cpp-dev-env:m1-latest
  docker run -d -v "$PATH_TO_CS128_DIR/src:/home/vagrant/src" -v "$PATH_TO_CS128_DIR/.shared:/home/vagrant/.shared" -v "$PATH_TO_CS128_DIR/.helpers:/home/vagrant/.helpers" -p 127.0.0.1:2222:22 --security-opt seccomp=unconfined --cap-add=SYS_PTRACE --name cs128env michaelrnowak/cpp-dev-env:m1-latest
else
  if [ "$(sysctl -in sysctl.proc_translated)" = "1" ]; then
    echo "Running on Apple Silcon with Rosetta 2"
    docker pull michaelrnowak/cpp-dev-env:m1-latest
    docker run -d -v "$PATH_TO_CS128_DIR/src:/home/vagrant/src" -v "$PATH_TO_CS128_DIR/.shared:/home/vagrant/.shared" -v "$PATH_TO_CS128_DIR/.helpers:/home/vagrant/.helpers" -p 127.0.0.1:2222:22 --security-opt seccomp=unconfined --cap-add=SYS_PTRACE --name cs128env michaelrnowak/cpp-dev-env:m1-latest
  else
    echo "Running on native Intel"
    docker pull michaelrnowak/cpp-dev-env:latest
    docker run -d -v "$PATH_TO_CS128_DIR/src:/home/vagrant/src" -v "$PATH_TO_CS128_DIR/.shared:/home/vagrant/.shared" -v "$PATH_TO_CS128_DIR/.helpers:/home/vagrant/.helpers" -p 127.0.0.1:2222:22 --security-opt seccomp=unconfined --cap-add=SYS_PTRACE --name cs128env michaelrnowak/cpp-dev-env:latest
  fi

fi

