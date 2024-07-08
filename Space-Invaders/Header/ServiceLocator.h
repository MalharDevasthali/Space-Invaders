#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"

class ServiceLocator
{
private:
    // Private Attributes:
    GraphicService* graphic_service;
    EventService* event_service;

    ServiceLocator();
    ~ServiceLocator();

    void createServices(); 			// Creates instances of all services.
    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

public:

    static ServiceLocator* getInstance(); 

    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders using the services.


    GraphicService* getGraphicService();
    EventService* getEventService();

};