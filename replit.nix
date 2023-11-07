{ pkgs }: {
	deps = [
   pkgs.root
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}