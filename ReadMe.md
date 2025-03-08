# Inventory System Plugin Overview

**The Inventory System Plugin is designed to manage and display inventories. It includes a robust set of structures and functions accessible via Blueprints, allowing for seamless integration and customization.**

1.Data Structures:
  - Inventory: Manages overall inventory data, suitable for saving game states.
  - ItemData: Defines attributes and characteristics of items.
  - InventorySlot: Holds specific details for each slot, including item information, position, and quantity.

2.Functionality:
  - A variety of functions (16 in InventoryComponent, 6 in the Function Library) facilitate operations such as adding/removing items, finding slots, and rotating items.
  - Functions include CountItems, AddSlot, SendItem, and more for efficient inventory management.

3.User Interface:
  - InventoryPanel: A UI widget displays the inventory, allowing for interaction and customization via subclasses like InventoryGrid and InventoryList.
  - InventoryPanelSlot: Manages individual slot presentation and data changes.

4.Management Controls:
  - Editor controls allow users to drag, drop, rotate, and manage items with simple mouse interactions, enhancing usability.

5.Item Assets and Actors:
  - Classes for static and dynamic item data management, enabling customization of item behaviors and characteristics.
  - This plugin provides a comprehensive solution for inventory management, streamlining the integration of inventory systems into any Unreal Engine project.
