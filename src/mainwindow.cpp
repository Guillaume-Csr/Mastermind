#include "mainwindow.h"

#include <QHBoxLayout>
#include <QMessageBox>

#include "coloritem.h"

MainWindow::MainWindow()
{
    createActions();
    createMenus();
}

void MainWindow::createActions()
{
    // ================ First tab ================= //

    newGameAction = new QAction(tr("New Game"), this);
    newGameAction->setShortcut(QKeySequence(tr("F2")));
    QObject::connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

    statisticsAction = new QAction(tr("Statistics"), this);
    statisticsAction->setShortcut(QKeySequence(tr("F4")));
    QObject::connect(statisticsAction, SIGNAL(triggered()), this, SLOT(statistics()));

    optionsAction = new QAction(tr("Options"), this);
    optionsAction->setShortcut(tr("F5"));
    QObject::connect(optionsAction, SIGNAL(triggered()), this, SLOT(options()));

    instructionsAction = new QAction(tr("Instructions"), this);
    instructionsAction->setShortcut(QKeySequence(tr("F6")));
    QObject::connect(instructionsAction, SIGNAL(triggered()), this, SLOT(instructions()));

    rulesAction = new QAction(tr("Rules"), this);
    rulesAction->setShortcut(QKeySequence(tr("F7")));
    QObject::connect(rulesAction, SIGNAL(triggered()), this, SLOT(rules()));

    exitAction = new QAction(tr("Exit"), this);
    exitAction->setShortcut(QKeySequence::Close);
    QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));

    // =============== Second tab ================ //

    aboutAction = new QAction(tr("About Mastermind"), this);
    aboutAction->setShortcut(QKeySequence(tr("F1")));
    QObject::connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    tipsAction = new QAction(tr("Tips"), this);
    tipsAction->setShortcut(QKeySequence(tr("F12")));
    QObject::connect(tipsAction, SIGNAL(triggered()), this, SLOT(tips()));
}

void MainWindow::createMenus()
{
    game = menuBar()->addMenu(tr("Game"));
    game->addAction(newGameAction);
    game->addAction(statisticsAction);
    game->addAction(optionsAction);
    game->addAction(instructionsAction);
    game->addAction(rulesAction);
    game->addAction(exitAction);

    help = menuBar()->addMenu(tr("Help"));
    help->addAction(aboutAction);
    help->addAction(tipsAction);
}


void MainWindow::newGame()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(QRectF(-140, -50, 500, 775));

    for(int i = 0 ; i < 8; i++)
    {
        ColorItem *item = new ColorItem;
        item->setPos(-100, 50 * i + 25 );

        scene->addItem(item);
    }


    board = new Board();
    scene->addItem(board);

    board->setI(0);
    QHBoxLayout *layout = new QHBoxLayout;
    view = new GraphicsView(scene);
    layout->addWidget(view);

    QWidget * widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("Mastermind - Release - Version 1.4.4"));
    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::statistics()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setText(tr("Statistics are not available in version 1.4.4"));
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->exec();
}

void MainWindow::options()
{
    int answer = QMessageBox::warning(this, tr("Options"), tr("No translator available in version 1.4.4"), QMessageBox::Ok);
    if( answer == QMessageBox::Ok )
    {
        QMessageBox::information(this, tr("Sorry"), tr("We apologize for the inconvenience."));
    }
}

void MainWindow::instructions()
{
    QMessageBox *msgBox = new QMessageBox;

    msgBox->setText(tr("<h1>Mastermind: instructions</h1> \
                       <section> \
                       <p><strong>How to play</strong><p> \
                       <p>Drag and drop to a large hole in the right row follow by an arrow. Click validate when you think you find the combination.</p> \
                       </section>"));
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}

void MainWindow::rules()
{
    QMessageBox *msgBox = new QMessageBox;

    msgBox->setText(tr("<h1>Mastermind: rules and basics</h1> \
                       <section> \
                       <p><strong>The objective</strong><p> \
                       <p>You are the Codebreaker. You have up to ten opportunities to try and duplicate the colour and the exact position of the hidden Code Pegs without ever seeing them.<p> \
                       </section> \
                       <section> \
                       <p><strong>The board</strong><p> \
                       De-Coding Board: Ten rows of large holes (Code Peg holes) and ten groups of small( Key Peg holes, and four shielded holes(for the hidden code)) \
                       </section>"));
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}

void MainWindow::exit()
{
    MainWindow::close();
}

void MainWindow::about()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setText(tr("Danick is the creator of Mastermind. He's studing at the Cegep. This game is designed with Qt 5.0 in c++. Fair enough. You must try one game of Mastermind... it's incredibly awesome!"));
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}

void MainWindow::tips()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setText(tr("<h3>Tips to be the King in Mastermind.</h3><ul><li>Keep cool and stay awesome.</li></ul>"));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->exec();
}
