#pragma once

#include <QObject>
#include <QString>

namespace muse {
namespace app {

class AiPromptPanelModel : public QObject {
    Q_OBJECT

    // Property to control if the send button is enabled
    Q_PROPERTY(bool sendEnabled READ sendEnabled NOTIFY sendEnabledChanged)

public:
    explicit AiPromptPanelModel(QObject* parent = nullptr);
    ~AiPromptPanelModel() override;

    // Getter for sendEnabled
    bool sendEnabled() const;

    // Method callable from QML to send the prompt
    Q_INVOKABLE void sendPrompt(const QString& prompt);

signals:
    // Notification signal for sendEnabled property
    void sendEnabledChanged();

    // Signal to notify core logic to process the prompt
    void promptReadyToSend(const QString& prompt);

public slots:
    // Slot to update the enabled state (e.g., called from C++ logic)
    void setSendEnabled(bool enabled);

private:
    bool m_sendEnabled = true; // Default to enabled
    // Add any other necessary private members or connections later
};

} // namespace app
} // namespace muse