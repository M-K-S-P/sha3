{ pkgs }: {
	deps = [
		pkgs.toybox
  pkgs.sudo
  pkgs.python39Full
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}