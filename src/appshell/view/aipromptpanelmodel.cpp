#include "aipromptpanelmodel.h"

// Potentially include headers for AI backend interaction

namespace muse {
namespace app {

AiPromptPanelModel::AiPromptPanelModel(QObject* parent) : QObject(parent) {
    // Initialize members, connect to AI backend signals if necessary
    // For now, it's fairly simple
}

AiPromptPanelModel::~AiPromptPanelModel() {
    // Clean up resources if necessary
}

bool AiPromptPanelModel::sendEnabled() const {
    return m_sendEnabled;
}

void AiPromptPanelModel::setSendEnabled(bool enabled) {
    if (m_sendEnabled != enabled) {
        m_sendEnabled = enabled;
        emit sendEnabledChanged();
    }
}

void AiPromptPanelModel::sendPrompt(const QString& prompt) {
    if (!prompt.trimmed().isEmpty() && m_sendEnabled) {
        // Disable send button immediately to prevent double clicks
        setSendEnabled(false);

        // Emit signal for the core logic/AI service to pick up
        emit promptReadyToSend(prompt.trimmed());

        // Note: The C++ backend service that handles the prompt
        // should call setSendEnabled(true) when it's ready for another prompt.
        // For now, we'll just re-enable it here for demonstration,
        // but this will likely need refinement based on the actual AI interaction.
        // setSendEnabled(true); // <-- Remove/modify this based on actual backend flow
    }
}

} // namespace app
} // namespace muse