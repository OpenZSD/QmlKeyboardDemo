#ifndef STATUSKEY_H
#define STATUSKEY_H

#include <QObject>
#include <map>

class StatusKey : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)

public:
    StatusKey(QObject *parent = nullptr) : QObject(parent) {}

    bool status() const { return mStatus; }
    void setStatus(const bool &status);
    
    QString key() const { return mKey; }
    void setKey(const QString &key);
    
    static void toggle(std::string k);

signals:
    void statusChanged();
    void keyChanged();

private:
    bool mStatus{false};
    QString mKey;
    
public:
    static std::map<std::string,StatusKey*> sKeys;
};

#endif // STATUSKEY_H
