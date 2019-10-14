Vagrant.configure("2") do |config|
  config.vm.box = "centos/7"
  config.vagrant.plugins = ["vagrant-vbguest"]

  config.vm.provider "virtualbox" do |provider|
    provider.customize ["modifyvm", :id, "--usb", "on"]
    provider.customize ['usbfilter', 'add', '0', '--target', :id, '--name', 'Sigma Designs Inc.', '--vendorid', '0x0658', '--productid', '0x0200']
  end

	config.vm.provision :docker

  config.vm.synced_folder ".", "/vagrant", type: "smb"

	config.vm.network "forwarded_port", guest: 8123, host: 8123
end
