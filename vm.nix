{ pkgs, ... }:

{
  imports = [
    <nixpkgs/nixos/modules/virtualisation/qemu-vm.nix>
  ];

  networking.hostName = "labmon";

  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  virtualisation.memorySize = 2048;
  virtualisation.cores = 2;

  # user info
  users.users.ali_lab = {
    isNormalUser = true;
    extraGroups = ["wheel"];
    initialPassword = "test";
  };

  environment.systemPackages = [
    ( import ./default.nix { inherit pkgs; })
  ];

  system.stateVersion = "24.05";
}