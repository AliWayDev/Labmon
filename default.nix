{ pkgs ? import <nixpkgs> { } }:

pkgs.stdenv.mkDerivation {
    pname = "labmon";
    version = "0.1.0";

    src = pkgs.lib.fileset.toSource {
        root = ./.;
        fileset = pkgs.lib.fileset.unions [
            ./main.cpp
            ./CMakeLists.txt
        ];
    };

    nativeBuildInputs = [
        pkgs.cmake
    ];
}