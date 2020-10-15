#ifndef BOARD_H
#define BOARD_H

#include "boarddesign.h"
#include "boardbutton.h"
#include "boardSecret.h" // change Secret -> secret

#include "codinghole.h"
#include "holereview.h"
#include "secrethole.h"

#include <QGraphicsView>

class Board : public BoardPart
{

    Q_OBJECT

public:
    Board(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void setI(int);
    int getI();
    void showMsgBox(QString);

public slots:
    void verification();
    void giveUp();

private:
    int blackHole;
    int whiteHole;
    int array_size;
    int m_i;
    QVector< QVector<CodingHole*> > codingHole;
    QVector< QVector<HoleReview*> > holeRewiew;
    QVector<SecretHole*> secretHole;
    BoardButton *boardButtonGiveUp;
    BoardButton *boardButton;
    BoardDesign *boardDesign;
    BoardSecret *boardSecret;
};

#endif // BOARD_H
