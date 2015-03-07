#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "graphicsview.h"
#include "board.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void newGame();
    void statistics();
    void options();
    void instructions();
    void rules();
    void exit();

    void about();
    void tips();

private:
    void createActions();
    void createMenus();

    QMenu *game;
    QAction *newGameAction;
    QAction *statisticsAction;
    QAction *optionsAction;
    QAction *instructionsAction;
    QAction *rulesAction;
    QAction *exitAction;

    QMenu *help;
    QAction *aboutAction;
    QAction *tipsAction;

    QGraphicsScene *scene;
    GraphicsView *view;

    Board *board;
};

#endif // MAINWINDOW_H
