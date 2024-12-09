#include "StatusKey.h"

std::map<std::string,StatusKey*> StatusKey::sKeys;

void StatusKey::setStatus(const bool &status)
{
    if (mStatus != status)
    {
        mStatus = status;
        emit statusChanged();
    }
}

void StatusKey::setKey(const QString &key)
{
    if (mKey != key)
    {
        sKeys[key.toStdString()] = this;
        mKey = key;
        emit keyChanged();
    }
}

void StatusKey::toggle(std::string k)
{
    if(sKeys.find(k) != sKeys.end())
    {
        sKeys[k]->setStatus(!sKeys[k]->status());
    }
}
