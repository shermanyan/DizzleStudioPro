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
            return "App/Resources/Textueres/PlayButtonGreen.png";
        case PAUSE_BUTTON:
            return "App/Resources/Textueres/PauseButtonGreen.png";
        case PLAY_BUTTON_GREY:
            return "App/Resources/Textueres/PlayButtonGrey.png";
        case PAUSE_BUTTON_RED:
            return "App/Resources/Textueres/PauseButtonRed.png";
        case MIC_BUTTON_RED:
            return "App/Resources/Textueres/MicButtonRed.png";
        case KEYBOARD_LABEL:
            return "App/Resources/Textures/Keyboard_Label.png";
        case DRUMPAD_LABEL:
            return "App/Resources/Textures/Drumpad_Label.png";
        case AUDIO_LABEL:
            return "App/Resources/Textures/Audio_Label.png";
        case VOCAL_LABEL:
            return "App/Resources/Textures/Vocals_Label.png";
        case EMPTY_LABEL:
            return "App/Resources/Textures/Empty_Label.png";
        case LAST_TEX:
            break;
    }
}

sf::Texture &Textures::getTexture(TextureEnums texture) {
    if (map.count(texture) == 0)
        load(texture);
    return map.at(texture);
}
