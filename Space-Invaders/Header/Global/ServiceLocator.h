#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Time/TimeService.h"

class ServiceLocator
{
private:
    // Private Attributes:
    GraphicService* graphic_service;
    EventService* event_service;
    PlayerService* player_service;
    TimeService* time_service;

    ServiceLocator();
    ~ServiceLocator();

    void createServices(); 			
    void clearAllServices(); 		

public:

    static ServiceLocator* getInstance(); 

    void initialize(); 			
    void update(); 				
    void render(); 				


    GraphicService* getGraphicService();
    EventService* getEventService();
    PlayerService* getPlayerService();
    TimeService* getTimeService();

};