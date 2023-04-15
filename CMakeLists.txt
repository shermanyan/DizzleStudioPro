cmake_minimum_required(VERSION 3.23)
project(DizzleStudioPro)

set(CMAKE_CXX_STANDARD 14)

include_directories(SFML_Resources/Components/ScrollableContainer)
include_directories(SFML_Resources/Components/TextInput)
include_directories(SFML_Resources/Components/Typing)
include_directories(SFML_Resources/Shapes)
include_directories(SFML_Resources/Tools)
include_directories(SFML_Resources/Tools/App)
include_directories(SFML_Resources/Tools/Enums)
include_directories(SFML_Resources/Tools/Helpers)
include_directories(SFML_Resources/Tools/History)

add_executable(DizzleStudioPro
        SFML_Resources/Components/ScrollableContainer/ScrollableContainer.cpp
        SFML_Resources/Components/ScrollableContainer/ScrollableContainer.h
        SFML_Resources/Components/ScrollableContainer/ScrollEnum.h
        SFML_Resources/Components/TextInput/Cursor.cpp
        SFML_Resources/Components/TextInput/Cursor.h
        SFML_Resources/Components/TextInput/TextBox.cpp
        SFML_Resources/Components/TextInput/TextBox.h
        SFML_Resources/Components/TextInput/TextboxLabel.cpp
        SFML_Resources/Components/TextInput/TextboxLabel.h
        SFML_Resources/Components/TextInput/TextInput.cpp
        SFML_Resources/Components/TextInput/TextInput.h
        SFML_Resources/Components/Typing/Letter.cpp
        SFML_Resources/Components/Typing/Letter.h
        SFML_Resources/Components/Typing/MultiText.cpp
        SFML_Resources/Components/Typing/MultiText.h
        SFML_Resources/Components/Typing/Typing.cpp
        SFML_Resources/Components/Typing/Typing.h
        SFML_Resources/Shapes/Squircle.cpp
        SFML_Resources/Shapes/Squircle.h
        SFML_Resources/Tools/App/AppComponent.h
        SFML_Resources/Tools/App/Application.cpp
        SFML_Resources/Tools/App/Application.h
        SFML_Resources/Tools/App/EventHandleable.h
        SFML_Resources/Tools/App/Updatable.h
        SFML_Resources/Tools/Enums/FontsEnum.h
        SFML_Resources/Tools/Enums/StatesEnum.h
        SFML_Resources/Tools/Helpers/KeyboardShortcuts.cpp
        SFML_Resources/Tools/Helpers/KeyboardShortcuts.h
        SFML_Resources/Tools/Helpers/MouseEvents.cpp
        SFML_Resources/Tools/Helpers/MouseEvents.h
        SFML_Resources/Tools/Helpers/Position.cpp
        SFML_Resources/Tools/Helpers/Position.h
        SFML_Resources/Tools/Helpers/States.cpp
        SFML_Resources/Tools/Helpers/States.h
        SFML_Resources/Tools/History/History.cpp
        SFML_Resources/Tools/History/History.h
        SFML_Resources/Tools/History/HistoryNode.h
        SFML_Resources/Tools/History/Snapshot.cpp
        SFML_Resources/Tools/History/Snapshot.h
        SFML_Resources/Tools/History/SnapshotInterface.h
        SFML_Resources/Tools/Fonts.cpp
        SFML_Resources/Tools/Fonts.h
        App/UIComponents/Panels/DynamicInstrumentPanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel.h
        App/UIComponents/Layer/Layer.cpp
        App/UIComponents/Layer/Layer.h
        App/UIComponents/Layer/Label.cpp
        App/UIComponents/Layer/Label.h
        App/UIComponents/Layer/Track.cpp
        App/UIComponents/Layer/Track.h
        App/UIComponents/Panels/LayersPanel.cpp
        App/UIComponents/Panels/LayersPanel.h
        App/UIComponents/Instruments/KeyBoard/Keyboard.cpp
        App/UIComponents/Instruments/KeyBoard/Keyboard.h
        App/UIComponents/Instruments/DrumPad/Pads.cpp
        App/UIComponents/Instruments/DrumPad/Pads.h
        App/UIComponents/Instruments/DrumPad/DrumPad.cpp
        App/UIComponents/Instruments/DrumPad/DrumPad.h
        App/UIComponents/Instruments/KeyBoard/Keys/Keys.cpp
        App/UIComponents/Instruments/KeyBoard/Keys/Keys.h
        App/UIComponents/Instruments/KeyBoard/Keys/OctaveKeys.cpp
        App/UIComponents/Instruments/KeyBoard/Keys/OctaveKeys.h
        App/UIComponents/Instruments/KeyBoard/Keys/BlackKey.cpp
        App/UIComponents/Instruments/KeyBoard/Keys/BlackKey.h
        App/UIComponents/Instruments/KeyBoard/Keys/WhiteKey.cpp
        App/UIComponents/Instruments/KeyBoard/Keys/WhiteKey.h
        App/AudioNode.cpp
        App/AudioNode.h
        App/UIComponents/Layer/DrawableAudioNode.cpp
        App/UIComponents/Layer/DrawableAudioNode.h
        App/UIComponents/SeekBar.cpp
        App/UIComponents/SeekBar.h
        main.cpp
#        TrackPrototypeTest.cpp
        )


target_link_libraries(DizzleStudioPro sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)