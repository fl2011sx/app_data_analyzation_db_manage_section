#############################################################################
# Makefile for building: tpapp_server_manage.app/Contents/MacOS/tpapp_server_manage
# Generated by qmake (3.0) (Qt 5.7.0)
# Project:  tpapp_server_manage.pro
# Template: app
# Command: /Users/hubohao/Qt5.7.0/5.7/clang_64/bin/qmake -spec macx-xcode -o tpapp_server_manage.xcodeproj/project.pbxproj tpapp_server_manage.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc
UIC       = /Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I. -I-I -I/usr/include/Python -I../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I../../Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I../../Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -I../../Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers: moc_mainwindow.cpp moc_usermanagewindow.cpp moc_welcomewindow.cpp\
	 moc_loginwindow.cpp moc_statisticswindow.cpp moc_waitingwindow.cpp\
	 moc_waitingthread.cpp moc_groupsetwindow.cpp ui_groupsetwindow.h ui_loginwindow.h ui_mainwindow.h\
	 ui_statisticswindow.h ui_usermanagewindow.h ui_waitingwindow.h\
	 ui_welcomewindow.h ui_welcomewindow.h ui_loginwindow.h\
	 ui_statisticswindow.h ui_waitingwindow.h ui_groupsetwindow.h
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp moc_usermanagewindow.cpp moc_welcomewindow.cpp moc_loginwindow.cpp moc_statisticswindow.cpp moc_waitingwindow.cpp moc_waitingthread.cpp moc_groupsetwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_usermanagewindow.cpp moc_welcomewindow.cpp moc_loginwindow.cpp moc_statisticswindow.cpp moc_waitingwindow.cpp moc_waitingthread.cpp moc_groupsetwindow.cpp
moc_mainwindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		global.hpp \
		Py_function_interface/MainFunctions.hpp \
		waitingwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		mainwindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib mainwindow.h -o moc_mainwindow.cpp

moc_usermanagewindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		global.hpp \
		Py_function_interface/MainFunctions.hpp \
		waitingwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		usermanagewindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib usermanagewindow.h -o moc_usermanagewindow.cpp

moc_welcomewindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		loginwindow.h \
		global.hpp \
		Py_function_interface/MainFunctions.hpp \
		waitingwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		mainwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		welcomewindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib welcomewindow.h -o moc_welcomewindow.cpp

moc_loginwindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		global.hpp \
		Py_function_interface/MainFunctions.hpp \
		waitingwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		mainwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		loginwindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib loginwindow.h -o moc_loginwindow.cpp

moc_statisticswindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		global.hpp \
		Py_function_interface/MainFunctions.hpp \
		waitingwindow.h \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QTableWidgetItem \
		statisticswindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib statisticswindow.h -o moc_statisticswindow.cpp

moc_waitingwindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		waitingwindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib waitingwindow.h -o moc_waitingwindow.cpp

moc_waitingthread.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers/QThread \
		waitingthread.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib waitingthread.h -o moc_waitingthread.cpp

moc_groupsetwindow.cpp: ../../Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers/QWidget \
		groupsetwindow.h \
		../../Qt5.7.0/5.7/clang_64/bin/moc
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/hubohao/Qt5.7.0/5.7/clang_64/mkspecs/macx-clang -I/Users/hubohao/Desktop/tpapp_server_manage -I/Users/hubohao/Desktop/tpapp_server_manage/-I -I/usr/include/Python -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/hubohao/Qt5.7.0/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/9.1.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/usr/include -I'/System/Library/Frameworks (framework directory)' -I'/Library/Frameworks (framework directory)' -F/Users/hubohao/Qt5.7.0/5.7/clang_64/lib groupsetwindow.h -o moc_groupsetwindow.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_groupsetwindow.h ui_loginwindow.h ui_mainwindow.h ui_statisticswindow.h ui_usermanagewindow.h ui_waitingwindow.h ui_welcomewindow.h ui_welcomewindow.h ui_loginwindow.h ui_statisticswindow.h ui_waitingwindow.h ui_groupsetwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_groupsetwindow.h ui_loginwindow.h ui_mainwindow.h ui_statisticswindow.h ui_usermanagewindow.h ui_waitingwindow.h ui_welcomewindow.h ui_welcomewindow.h ui_loginwindow.h ui_statisticswindow.h ui_waitingwindow.h ui_groupsetwindow.h
ui_groupsetwindow.h: groupsetwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic groupsetwindow.ui -o ui_groupsetwindow.h

ui_loginwindow.h: loginwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic loginwindow.ui -o ui_loginwindow.h

ui_mainwindow.h: mainwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_statisticswindow.h: statisticswindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic statisticswindow.ui -o ui_statisticswindow.h

ui_usermanagewindow.h: usermanagewindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic usermanagewindow.ui -o ui_usermanagewindow.h

ui_waitingwindow.h: waitingwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic waitingwindow.ui -o ui_waitingwindow.h

ui_welcomewindow.h: welcomewindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic welcomewindow.ui -o ui_welcomewindow.h

ui_welcomewindow.h: welcomewindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic welcomewindow.ui -o ui_welcomewindow.h

ui_loginwindow.h: loginwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic loginwindow.ui -o ui_loginwindow.h

ui_statisticswindow.h: statisticswindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic statisticswindow.ui -o ui_statisticswindow.h

ui_waitingwindow.h: waitingwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic waitingwindow.ui -o ui_waitingwindow.h

ui_groupsetwindow.h: groupsetwindow.ui \
		../../Qt5.7.0/5.7/clang_64/bin/uic
	/Users/hubohao/Qt5.7.0/5.7/clang_64/bin/uic groupsetwindow.ui -o ui_groupsetwindow.h

compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

