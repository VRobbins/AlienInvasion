#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include "BossSprayAttackSingle.h"
#include "stdlib.h"
#include "BossHealth.h"


class Boss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
        constructor for the boss
        @param Player* is a pointer to the player being used in the game
        @param BossHealth* a pointer to the health of the boss used in the game
    */
    Boss(Player* player, BossHealth* boss_health);

    /**
        gets the health of the boss
        @return the health of the boss
    */
    short int get_health() const;

    /**
        decreases the health of the boss
        @return the decreased health of the boss
    */
    unsigned short int decrease_health(unsigned short int amount);
    ~Boss();

public slots:
    /**
        releases the boss's spray attack
    */
    void sprayAttack();

private:
    int health;
    BossHealth* health_bar;
    BossSprayAttackSingle* bossSprayAttack;
    QTimer* sprayAttack_timer;
    QTimer* move_timer;
    Player* opponent;
    QPixmap* weapon;


};

#endif // BOSS_H
