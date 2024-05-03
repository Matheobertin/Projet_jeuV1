#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

class MyView : public QGraphicsView
{
    Q_OBJECT

public:

private:

protected:
    virtual void resizeEvent (QResizeEvent* event) {
        this->fitInView(sceneRect());
    }
};

#endif // MYVIEW_H
