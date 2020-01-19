#ifndef LAMP_H
#define LAMP_H

#include <QtWidgets>

#include "channel.h"

class Lamp : public QWidget
{
    Q_OBJECT
    
public:
    Lamp (Channel* channel, QWidget *parent = nullptr);
    ~Lamp ();

    void set_color (const QColor& color) { color_ = color; }
    void set_enabled (bool v) { enabled_ = v; }

private:
    void paintEvent (QPaintEvent*);
    void timerEvent (QTimerEvent*);
    void drawLamp (QPainter &paint);
    void clear (QPainter &paint);

private slots:
    void process_cmd (Command*);

private:
    bool enabled_;
    QColor color_;
};

#endif // LAMP_H
