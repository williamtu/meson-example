# .\meson59.exe --reconfigure build -Dpkg_config_path=C:\temp\dpdk\lib\pkgconfig\
# ninja -C build
project('example', 'c', 
   default_options: ['buildtype=debug', 'default_library=static'])

cc = meson.get_compiler('c')
includes = []
includes += include_directories('.')

pthread_inc_path = 'c:\\PTHREADS-BUILT\include'
includes += include_directories(pthread_inc_path)

dpdk_lib_path = 'c:\\temp\dpdk'
dpdk_inc_path = dpdk_lib_path + '\include'
includes += include_directories(dpdk_inc_path)

#add_project_link_arguments('-Wl,/INCLUDE:rte_pci_set_bus_master', language: 'c')
add_project_link_arguments('-Wl,/FORCE:MULTIPLE', language: 'c')
add_project_link_arguments('-Wl,/WHOLEARCHIVE', language: 'c')
add_project_link_arguments('-Wl,/OPT:NOREF', language: 'c')
add_project_link_arguments('-Wl,/DEBUG', language: 'c')

add_project_link_arguments('-lmincore', language: 'c')
add_project_link_arguments('-ladvapi32', '-lsetupapi', language: 'c')
add_project_link_arguments('-ldbghelp', language: 'c')

# dpdk_lib_deps = dependency('libdpdk', required : true, static : true) 

dpdk_libs = ['rte_eal', 'rte_ethdev', 'rte_hash', 'rte_kvargs', 'rte_mbuf', 'rte_net',
  'rte_mempool', 'rte_pci', 'rte_bus_pci', 'rte_ring', 'rte_cmdline', 'rte_telemetry',
  'rte_rcu']

dpdk_lib_deps = []
foreach lib:dpdk_libs
    dpdk_lib_deps += cc.find_library(lib, required : true, static : true,
      dirs: dpdk_lib_path + '\lib')
endforeach

mapfile = meson.project_source_root() + '/mylib.map'
vflag = '-Wl'.format(meson.current_source_dir(), mapfile)
mylib = static_library(
  'mylib', 'mylib.c',
#  dependencies : [],
#  include_directories : global_inc,
#  link_args : ['-Wl,--no-undefined', vflag],
  link_depends : mapfile,
#  link_with : sflow,
#  version : as_version,
#  soversion : as_soversion,

)
executable('demo', 'main.c',
  dependencies: dpdk_lib_deps,
  #  link_whole: dpdk_lib_deps,
  link_with: mylib,
  include_directories : includes)

