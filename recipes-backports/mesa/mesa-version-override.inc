PV = "26.1.5"
SRC_URI[sha256sum] = "79e421c7ce18cd9e790b8375920325779f10798630bf30e0b22f1a21c8617122"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"
SRC_URI += " \
	file://0001-clc-make-libclc-optional-for-configs-not-needing-it.patch \
	file://0002-clc-use-our-downstream-fork-of-libclc.patch \
"

# Use the mesa-libclc fork
PACKAGECONFIG[opencl] = "-Dgallium-rusticl=true -Dmesa-clc-bundle-headers=enabled, -Dgallium-rusticl=false, bindgen-cli-native clang mesa-libclc spirv-tools spirv-llvm-translator"

RDEPENDS:libopencl-mesa:remove = "${@bb.utils.contains('PACKAGECONFIG', 'opencl', 'libclc', '', d)}"
RDEPENDS:libopencl-mesa:append = "${@bb.utils.contains('PACKAGECONFIG', 'opencl', ' mesa-libclc', '', d)}"
