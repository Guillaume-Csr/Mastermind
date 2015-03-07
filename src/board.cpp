#include "board.h"

#include <QMessageBox>

Board::Board(QGraphicsItem *parent) : BoardPart(parent), blackHole(0), whiteHole(0), array_size(10),
    codingHole(array_size, QVector<CodingHole*>(4)), // 40 codinghole [ 4 x 10 ]
    holeRewiew(array_size, QVector<HoleReview*>(4)), // 40 holereview [ 4 x 10 ]
    secretHole(4)                                    // 4  secrethole [ 4 ]
{
    setFlag(ItemHasNoContents);

    boardButtonGiveUp = new BoardButton(this, "Give Up");
    boardButton = new BoardButton(this, "Validation");
    boardDesign = new BoardDesign(this);
    boardSecret = new BoardSecret(this);

    m_i = 0;

    // [1] Positioning the objects on the board.
    for( int i = 0 ; i < array_size ; i++ )
    {
        for( int j = 0 ; j < 4 ; j++ )
        {
            codingHole[i][j] = new CodingHole(this);
            codingHole[i][j]->setPos(j * 60, i * 60);
            codingHole[i][j]->setEnabled(false);
            codingHole[i][j]->setPainted(false);
        }

        for( int j = 0 ; j < 4 ; j++ )
        {
            holeRewiew[i][j] = new HoleReview(this);
            switch(j)
            {
            case 0:
                holeRewiew[i][j]->setPos(250 + 4, ( i * 60 ) + 3);
                break;
            case 1:
                holeRewiew[i][j]->setPos(250 + 4, ( i * 60 ) + 27);
                break;
            case 2:
                holeRewiew[i][j]->setPos(250 + 27, ( i * 60 ) + 3);
                break;
            case 3:
                holeRewiew[i][j]->setPos(250 + 27, ( i * 60 ) + 27);
            }
        }
    }

    boardButtonGiveUp->setPos(-110, 650);
    boardButton->setPos(-110, 590);
    boardDesign->setZValue(1);
    boardSecret->setZValue(2);

    for( int i = 0 ; i < 4; i++)
    {
        secretHole[i] = new SecretHole(this);
        secretHole[i]->setPos(10 + (60 * i), 600 + 25);
    }

    // [2] The first row will be enabled when player starts the game.
    for(int j = 0 ; j < 4 ; j++)
    {
        codingHole[0][j]->setEnabled(true);
    }

    // [3] Check if all codingHole have a color.
    QObject::connect(boardButtonGiveUp, SIGNAL(mouseReleased()), boardButtonGiveUp, SLOT(clickSlot()));
    QObject::connect(boardButtonGiveUp, SIGNAL(clickSignal()), this, SLOT(giveUp()));
    QObject::connect(boardButton, SIGNAL(mouseReleased()), boardButton, SLOT(clickSlot()));
    QObject::connect(boardButton, SIGNAL(clickSignal()), this, SLOT(verification()));
    boardButton->setClick(false);

}

QRectF Board::boundingRect() const
{
    return QRectF();
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Board::setI(int i)
{
    m_i = i;
}

int Board::getI()
{
    return m_i;
}

void Board::showMsgBox(QString string)
{
    QMessageBox msgBox;
    msgBox.setText(string);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void Board::giveUp()
{
    boardSecret->setTransparency(0);
    showMsgBox(tr("You give up!"));
    boardButtonGiveUp->setEnabled(false);
    boardButton->setEnabled(false);
    for(int j = 0; j < 4 ; j++)
    {
        codingHole[getI()][j]->setEnabled(false);
    }
}

void Board::verification()
{
    int i = m_i;
    int h = 0, l = 0;
    int specialCheck = 0;
    bool temporary = false;
    bool win = false;
    bool once = false;

    for(int j = 0; j < 4 ; j++)
    {
        if(codingHole[i][j]->getPainted() == false)
        {
            showMsgBox(tr("Forget some code peg holes ?"));
            return;
        }
    }

    for(int j = 0; j < 4 ; j++)
    {
        codingHole[i][j]->setEnabled(false);
    }

    // [4] Check white and black hole
    for(int j = 0; j < 4 ; j++)
    {
        // HIGH COUNT
        h = 0;
        for( int k = 0; k < 4; k++)
        {
            if( codingHole[i][k]->getImageNumber() == codingHole[i][j]->getImageNumber())
            {
                h++;
            }
        }

        // LOW COUNT [CONSTANT]
        l = 0;
        for( int k = 0; k < 4; k++)
        {
            if( secretHole[k]->getImageNumber() == codingHole[i][j]->getImageNumber())
            {
                l++;
            }
        }

        if(h == 2 && l == 1)
        {
            specialCheck++;
        }

        if(codingHole[i][j]->getImageNumber() == secretHole[j]->getImageNumber())
        {
            blackHole++;
        }
        else if(codingHole[i][j]->getImageNumber() == secretHole[((j > 0) ? 0 : 1)]->getImageNumber())
        {
            whiteHole++;
            temporary = true;
        }
        else if(codingHole[i][j]->getImageNumber() == secretHole[((j > 1) ? 1 : 2)]->getImageNumber())
        {
            whiteHole++;
            temporary = true;
        }
        else if(codingHole[i][j]->getImageNumber() == secretHole[((j > 2) ? 2 : 3)]->getImageNumber())
        {
            whiteHole++;
            temporary = true;
        }

        if(codingHole[i][j]->getImageNumber() != secretHole[j]->getImageNumber() && temporary == true)
        {
            temporary = false;
            if(h > l && once == false)
            {                
                l++;
                whiteHole--;
                if( h == 2)
                {
                    once = true;
                }
            }
        }
    }

    // [5] Check if 2 - 1 is done 4 times
    if(specialCheck == 4)
    {
        whiteHole--;
    }

    for(int j = 0; j < 4 ; j++ )
    {
        if( blackHole > 0 )
        {
            holeRewiew[i][j]->blackPaint();
            if(blackHole == 4)
            {
                win = true;
            }
            blackHole--;
        }
        else if( whiteHole > 0 )
        {
            holeRewiew[i][j]->whitePaint();
            whiteHole--;
        }
    }

    // [6] Check if the Codebreaker wins the game
    if(win)
    {
        boardSecret->setTransparency(0);
        showMsgBox(tr("You win. Click new game in the menu."));
        boardButton->setEnabled(false);
        boardButtonGiveUp->setEnabled(false);
        i = 0;
    }
    else
    {
        // [7] Reset value
        blackHole = 0;
        whiteHole = 0;

        // [8] Change the line (incrementation)
        m_i++;
        i++;

        // [9] Check if the Codebreaker fails the game
        if( i >= 10)
        {
            boardSecret->setTransparency(0);
            showMsgBox(tr("You lose. Click new game in the menu."));
            boardButton->setEnabled(false);
            boardButtonGiveUp->setEnabled(false);
            i = 9;
            return;
        }

        for(int j = 0; j < 4 ; j++)
        {
            codingHole[i][j]->setEnabled(true);
        }
        boardDesign->setPos(0, i*60);
    }
    scene()->update();
    return;
}
