//
// Created by Sherman Yan on 12/6/22.
//

#include "Textures.h"

std::map<TextureEnums, sf::Texture> Textures::map;

void Textures::load(TextureEnums texture) {
    if (map.count(texture) == 0 &&!map[texture].loadFromFile(getPath(texture)))
        exit(20);
}

std::string Textures::getPath(TextureEnums texture) {
    switch (texture){
        case PLAY_BUTTON:
            return "App/Resources/Textures/PanelControls/PlayButtonGreen.png";
        case PAUSE_BUTTON:
            return "App/Resources/Textures/PanelControls/PauseButtonGreen.png";
        case PLAY_BUTTON_GREY:
            return "App/Resources/Textures/PanelControls/PlayButtonGrey.png";
        case PAUSE_BUTTON_RED:
            return "App/Resources/Textures/PanelControls/PauseButtonRed.png";
        case MIC_BUTTON_RED:
            return "App/Resources/Textures/PanelControls/MicButtonRed.png";
        case KEYBOARD_LABEL:
            return "App/Resources/Textures/TrackLabels/Keyboard_Label.png";
        case DRUMPAD_LABEL:
            return "App/Resources/Textures/TrackLabels/Drumpad_Label.png";
        case AUDIO_LABEL:
            return "App/Resources/Textures/TrackLabels/Audio_Label.png";
        case VOCAL_LABEL:
            return "App/Resources/Textures/TrackLabels/Vocals_Label.png";
        case EMPTY_LABEL:
            return "App/Resources/Textures/TrackLabels/Empty_Label.png";
        case DROP_DOWN_MENU:
            return "App/Resources/Textures/TrackLabels/DropDownMenu.png";
        case DROP_DOWN_OVERLAY:
            return "App/Resources/Textures/TrackLabels/DropDownOverLap.png";
        case TRACKCONTROLS_FORWARD:
            return "App/Resources/Textures/TrackControls/TrackControls_Forward.png";
        case TRACKCONTROLS_LOOP:
            return "App/Resources/Textures/TrackControls/TrackControls_Loop.png";
        case TRACKCONTROLS_PAUSE:
            return "App/Resources/Textures/TrackControls/TrackControls_Pause.png";
        case TRACKCONTROLS_PLAY:
            return "App/Resources/Textures/TrackControls/TrackControls_Play.png";
        case TRACKCONTROLS_REWIND:
            return "App/Resources/Textures/TrackControls/TrackControls_Rewind.png";
        case TRACKCONTROLS_FORWARD_LIGHT:
            return "App/Resources/Textures/TrackControls/TrackControls_Forward_Light.png";
        case TRACKCONTROLS_LOOP_LIGHT:
            return "App/Resources/Textures/TrackControls/TrackControls_Loop_Light.png";
        case TRACKCONTROLS_REWIND_LIGHT:
            return "App/Resources/Textures/TrackControls/TrackControls_Rewind_Light.png";
        case AUDIOBARS:
            return "App/Resources/Textures/SplashScreen/AudioBars.png";
        case LAST_TEX:
            break;

    }
}

sf::Texture &Textures::getTexture(TextureEnums texture) {
    if (map.count(texture) == 0)
        load(texture);
    return map.at(texture);
}
