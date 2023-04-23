cmake_minimum_required(VERSION 3.23)
project(DizzleStudioPro)

set(CMAKE_CXX_STANDARD 14)

include_directories(App)
include_directories(App/Resources)
include_directories(App/UIComponents/Instruments/DrumPad)
include_directories(App/UIComponents/Instruments/Keyboard)
include_directories(App/UIComponents/Instruments/Keyboard/Keys)
include_directories(App/UIComponents/Panels/DynamicInstrumentPanel)
include_directories(App/UIComponents/Panels/DynamicInstrumentPanel/Base)
include_directories(App/UIComponents/Panels/DynamicInstrumentPanel/Panels)
include_directories(App/UIComponents/Panels/LayersPanel)
include_directories(App/UIComponents/Track)
include_directories(SFML_Resources/Components/ScrollableContainer)
include_directories(SFML_Resources/Components/TextInput)
include_directories(SFML_Resources/Components/Typing)
include_directories(SFML_Resources/Shapes)
include_directories(SFML_Resources/Tools)
include_directories(SFML_Resources/Tools/App)
include_directories(SFML_Resources/Tools/Enums)
include_directories(SFML_Resources/Tools/Helpers)
include_directories(SFML_Resources/Tools/History)
include_directories(App/Resources/Sounds)
include_directories(App/UIComponents/AudioRecording)
include_directories(App/UIComponents/MusicTrackSelection)
include_directories(App/Resources/Textueres)
add_executable(DizzleStudioPro
        App/Resources/Textures.cpp
        App/Resources/Textures.h
        App/Resources/TexturesEnum.h
        App/UIComponents/Instruments/DrumPad/DrumPad.cpp
        App/UIComponents/Instruments/DrumPad/DrumPad.h
        App/UIComponents/Instruments/DrumPad/Pads.cpp
        App/UIComponents/Instruments/DrumPad/Pads.h
        App/UIComponents/Instruments/Keyboard/Keys/Key.cpp
        App/UIComponents/Instruments/Keyboard/Keys/Key.h
        App/UIComponents/Instruments/Keyboard/Keys/OctaveKeys.cpp
        App/UIComponents/Instruments/Keyboard/Keys/OctaveKeys.h
        App/UIComponents/Instruments/Keyboard/Keyboard.cpp
        App/UIComponents/Instruments/Keyboard/Keyboard.h
        App/UIComponents/Panels/DynamicInstrumentPanel/Base/BasePanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel/Base/BasePanel.h
        App/UIComponents/Panels/DynamicInstrumentPanel/Base/PanelTypeEnum.h
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/EmptyPanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/EmptyPanel.h
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/KeyboardPanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/KeyboardPanel.h
        App/UIComponents/Panels/DynamicInstrumentPanel/DynamicInstrumentPanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel/DynamicInstrumentPanel.h
        App/UIComponents/Panels/LayersPanel/LayersPanel.cpp
        App/UIComponents/Panels/LayersPanel/LayersPanel.h
        App/UIComponents/Track/DrawableAudioNode.cpp
        App/UIComponents/Track/DrawableAudioNode.h
        App/UIComponents/Track/TrackLabel.cpp
        App/UIComponents/Track/TrackLabel.h
        App/UIComponents/Track/Layer.cpp
        App/UIComponents/Track/Layer.h
        App/UIComponents/Track/SeekBar.cpp
        App/UIComponents/Track/SeekBar.h
        App/UIComponents/Track/Track.cpp
        App/UIComponents/Track/Track.h
        App/AudioNode.cpp
        App/AudioNode.h
        App/StudioMain.cpp
        App/StudioMain.h
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
        SFML_Resources/Tools/App/Transformable.cpp
        SFML_Resources/Tools/App/Transformable.h
        SFML_Resources/Tools/App/Updatable.h
        SFML_Resources/Tools/Enums/FontsEnum.h
        SFML_Resources/Tools/Enums/StatesEnum.h
        SFML_Resources/Tools/Helpers/KeyboardShortcuts.cpp
        SFML_Resources/Tools/Helpers/KeyboardShortcuts.h
        SFML_Resources/Tools/Helpers/MouseEvents.cpp
        SFML_Resources/Tools/Helpers/MouseEvents.h
        SFML_Resources/Tools/Helpers/Position.cpp
        SFML_Resources/Tools/Helpers/Position.h
        SFML_Resources/Tools/Helpers/SpriteImage.cpp
        SFML_Resources/Tools/Helpers/SpriteImage.h
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
        App/UIComponents/AudioRecording/AudioVisualizer.h
        App/UIComponents/AudioRecording/AudioVisualizer.cpp
        App/UIComponents/MusicTrackSelection/StaticAudioVisualizer.cpp
        App/UIComponents/MusicTrackSelection/StaticAudioVisualizer.h
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/AudioRecordingPanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/AudioRecordingPanel.h
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/StaticVisualizerPanel.cpp
        App/UIComponents/Panels/DynamicInstrumentPanel/Panels/StaticVisualizerPanel.h
#        LiveVisualizerTester.cpp
        DizzleStudioProApp_main.cpp
#        KeyboardTester.cpp
#        RecorderTester.cpp
#        TrackPrototypeTester.cpp
        App/UIComponents/Instruments/SoundKeys.h SFML_Resources/Tools/Clock.cpp SFML_Resources/Tools/Clock.h App/UIComponents/Track/TimeBar.cpp App/UIComponents/Track/TimeBar.h App/UIComponents/Instruments/Keyboard/SoundKeyPair.h)

target_link_libraries(DizzleStudioPro sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

