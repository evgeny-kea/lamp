#include "lamp.h"

Lamp::Lamp (Channel* channel, QWidget *parent)
    : QWidget (parent)
{
    resize (200,200);
    color_ = QColor (255, 255, 255);
    enabled_ = false;

    connect (channel, SIGNAL (new_cmd (Command*)), SLOT (process_cmd (Command*)));

    startTimer (100);
}

Lamp::~Lamp ()
{
}

void Lamp::timerEvent(QTimerEvent *)
{
    update ();
}

void Lamp::paintEvent (QPaintEvent *)
{
    QPainter paint (this);
    clear (paint);
    drawLamp (paint);
}

void Lamp::drawLamp (QPainter &paint)
{
    if (enabled_)
    {
        paint.setPen (QPen (Qt::black, 3, Qt::SolidLine));
        paint.setBrush (QBrush (color_));
        paint.drawEllipse (50, 50, 100, 100);
    }
}

void Lamp::clear (QPainter &paint)
{
    paint.eraseRect (0, 0, 200, 200);
}

void Lamp::process_cmd (Command* cmd)
{
    cmd->exec (this);
}
