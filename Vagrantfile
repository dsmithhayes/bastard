##
# Sets up an ideal testing environment for Bastard using HHVM and NGiNX
##

Vagrant.configure(2) do |config|
  config.vm.box = "debian/jessie64"

  config.vm.provider "virtualbox" do |vb|
     vb.memory = "1024"
  end

  config.vm.network "forwarded_port", guest: 80, host: 4567
  config.vm.provision "shell", path: "bootstrap.sh"
end
