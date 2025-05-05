// GlobalConfig.h
#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

#include <QString>

class GlobalConfig {
private:
    QString m_username;
    bool m_isSet = false;

    // Private constructor
    GlobalConfig() = default;

    // Kopyalama yasak
    GlobalConfig(const GlobalConfig&) = delete;
    GlobalConfig& operator=(const GlobalConfig&) = delete;

    GlobalConfig(GlobalConfig&&) = delete;
    GlobalConfig& operator=(GlobalConfig&&) = delete;

public:


    static GlobalConfig& username() {
        static GlobalConfig _instance;
        return _instance;
    }

    void setUsernameOnce(const QString& value) {
        if (!m_isSet) {
            m_username = value;
            m_isSet = true;
        }
    }

    QString getUsername() const {
        return m_username;
    }
};

#endif // GLOBALCONFIG_H
