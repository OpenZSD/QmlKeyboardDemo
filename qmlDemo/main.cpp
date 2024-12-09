#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QList>
#include <QVariant>
#include <QQuickItem>
#include <QKeyEvent>
#include "StatusKey.h"
#include <thread>
#include <SDL2/SDL.h>
#include <iostream>
#include <chrono>
#include <cstdlib>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<StatusKey>("StatusKey", 1, 0, "StatusKey");
    
    engine.load(QUrl(QStringLiteral("qrc:/BaseFsFrame.qml")));
    QList<QObject*> xs = engine.rootObjects();
    if (xs.count() == 0)
    {
       Q_ASSERT_X(false, "Creating C++ runtime", "Your QML file seems buggy");
    }
    QQuickWindow *window = qobject_cast<QQuickWindow*>(xs.at(0) );
    
    bool run = true;
    auto stlKeyFunc = [&](bool *cont)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        }
        else
        {
        SDL_Window* win = SDL_CreateWindow("GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       100, 100, 0);
        
            SDL_Event event;
            while(*cont)
            {
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                while(SDL_PollEvent(&event))
                {
                    if(event.type == SDL_KEYDOWN)
                    {
                        if(StatusKey::sKeys.find(std::string(1, char(event.key.keysym.sym))) != StatusKey::sKeys.end())
                        {
                            StatusKey::sKeys[std::string(1, char(event.key.keysym.sym))]->setStatus(true);
                        }
                    }
                    else if(event.type == SDL_KEYUP)
                    {
                        if(StatusKey::sKeys.find(std::string(1, char(event.key.keysym.sym))) != StatusKey::sKeys.end())
                        {
                            StatusKey::sKeys[std::string(1, char(event.key.keysym.sym))]->setStatus(false);
                        }
                    }
                }
                /*char c = 'a'+(rand()%20);
                std::string s(1, c);
                if(StatusKey::sKeys.find(s) != StatusKey::sKeys.end())
                {
                    StatusKey::sKeys[s]->setStatus(!StatusKey::sKeys[s]->status());
                }*/
            }
        }
    };
    std::thread t(stlKeyFunc, &run);
    
    //QMetaObject::invokeMethod(window, "getKB");
    //StatusKey::toggle("a");
    auto res = app.exec();
    run = false;
    t.join();
    return res;
}
