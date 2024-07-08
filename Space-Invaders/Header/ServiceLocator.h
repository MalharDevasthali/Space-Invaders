#pragma once

#pragma once

class ServiceLocator
{
private:

    ServiceLocator();
    ~ServiceLocator();

    void createServices(); 			// Creates instances of all services.
    void clearAllServices(); 		//	Deletes and deallocates memory for all services.

public:

    static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

    void initialize(); 			//	Initializes the ServiceLocator.
    void update(); 				//	Updates all services.
    void render(); 				//	Renders using the services.

    // Methods to Get Specific Services: 
    //EventService* getEventService();   // Retrieve the EventService instance
    //GraphicService* getGraphicService();   // Retrieve the GraphicService instance

};