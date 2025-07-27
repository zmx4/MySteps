add_rules("mode.debug", "mode.release")

add_includedirs("C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.29.30133/include")

add_includedirs("C:/Env/MSYS/mingw64/include/c++/14.2.0")

add_includedirs("C:/Env/MSYS/mingw64/include/c++/14.2.0/x86_64-w64-mingw32")

target("nowcoder")
	set_kind("binary")
	add_includedirs("C:/Env/MSYS/mingw64/include")
	add_includedirs("%projectdir%/include")
	set_toolset("cxx", "gcc")
	add_files("nowcoder/*/*/*.cpp")
	set_optimize("faster")
	set_languages("c23", "c++23")

target("PTA")
	set_kind("binary")
	add_includedirs("C:/Env/MSYS/mingw64/include")
	add_includedirs("%projectdir%/include")
	set_toolset("cxx", "gcc")
	add_files("PTA/*/*.cpp")
	set_optimize("faster")
	set_languages("c23", "c++20")

target("LuoGu")
	set_kind("binary")
	add_includedirs("C:/Env/MSYS/mingw64/include")
	add_includedirs("%projectdir%/include")
	set_toolset("cxx", "gcc")
	add_files("Lg/*/*.cpp")
	set_optimize("faster")
	set_languages("c23", "c++20")

target("acwing")
	set_kind("binary")
	add_includedirs("C:/Env/MSYS/mingw64/include")
	add_includedirs("%projectdir%/include")
	set_toolset("cxx", "gcc")
	add_files("acwing/*/*.cpp")
	set_optimize("faster")
	set_languages("c23", "c++20")

-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

