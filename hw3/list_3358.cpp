//list_3358.cpp
//implementation of a very simple curssor-based List ADT
//This is a simple array implementation

#include "list_3358.h"
#include <iostream>


using namespace std;
using namespace cs3358;     
      
      List_3358::List_3358 ( ) {
     
         head = NULL;
         tail = NULL;
         cursor = NULL;      
      }
      
      
      List_3358::List_3358 ( const List_3358 & src ) {

         if (src.head == NULL)
         {
            head = NULL;
            tail = NULL;
            cursor = NULL;
         }
         else
         {
            Node *temp;
            Node *prev = NULL;

            for (Node *p = src.head; p != NULL; p=p->next)
            {
               temp = new Node;
               temp->value = p->value;
               temp->next = NULL;
         
               if (prev == NULL)
                  prev = temp;
               else
               {
                  prev->next = temp;
                  prev = temp;
               }
 
               if (p == src.head)
                  head = temp;
               if (p == src.cursor)
                  cursor = temp;
               if (p == src.tail)
                  tail = temp;
            }
         }
            
      }
      
      
      List_3358::~List_3358 ( ) {

         Node *p = head;

         while (head != NULL)
         {
            head = head->next;
            delete p;
            p = head;
         }
 
      }

      //************************************
      //Mutator(s)
      
      void List_3358::insert (const value_type & item) {
 
         if (!isFull())
         {
            Node *temp = new Node;
            temp->value = item;
            temp->next = NULL;

            if (isEmpty())
            {
               head = temp;
               tail = temp;
            }
            else if (atEOL())
            {
               tail->next = temp;
               tail = temp;
            }
            else
            {
               if (cursor == head) //inserting at head
               {
                  temp->next = head;
                  head = temp;
               }
               else
               {
                  Node *p = head;
                  while (p->next != cursor)
                     p = p->next;

                  p->next = temp;
                  temp->next = cursor;
               }
            }
         }
      }        
            
         
  
      void List_3358::remove() {
      
         Node *p = head;

         if (!atEOL() && !isEmpty())
         {
            if (cursor == head)
            {
               head = head->next;
               delete p;
               cursor = head;
 
               if (head == NULL)
                  tail = NULL;  //deleted only item in list
            }
            else
            {
               while (p->next != cursor)
                  p = p->next;

               p->next = cursor->next;

               if (cursor == tail)
               {
                  delete cursor;
                  tail = p;
                  cursor = NULL;
               }
               else
               {
                  delete cursor;
                  cursor = p->next;
               }
            }   
         }      
            
               
   
      }


      void List_3358::reset ( ) {
         
         cursor = head;
  
      }


      
      bool List_3358::advance ( ) {

         if (!atEOL())
            cursor = cursor->next;

         return (!atEOL()); 
      }

      

      //*******************
      // Accessor(s)
      

      bool List_3358::isEmpty ( ) const {
      
         return (head == NULL);
         
      }


   
      bool List_3358::atEOL ( ) const {
      
         return (cursor==NULL); 
        
      }
      




      bool List_3358::isFull ( ) const {
         
      }


            
      List_3358::value_type List_3358::getCurrent ( ) const {

         if (!atEOL())
            return cursor->value;   
      
      }



      
