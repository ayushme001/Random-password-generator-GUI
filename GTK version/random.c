


//for compiling use - 
// gcc random.c -o random `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`



#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *result;
static GtkWidget *show;
static GtkWidget *print;


void do_copy(GtkWidget *copy, gpointer data)
{
    char a[50]=" Your password has been copied to clipboard !";
    gtk_label_set_text(GTK_LABEL(print), a);
}

void do_calculate(GtkWidget *calculate, gpointer data) 
{
    
    GtkClipboard* clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    int n = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1)));
  
    int i = 0;
    
    char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/_.-+=<>?";
        srand(time(NULL));
      
        char c[n];
        char buffer[32];
        for(i = 0; i < n; i++)
        {  
            c[i] = a[rand() % (sizeof(a))];
            
          
        }

    gtk_clipboard_set_text(clipboard, c, -1);
    gtk_label_set_text(GTK_LABEL(result), c);
}


int main(int argc, char **argv) 
{
    
    GtkWidget *window, *grid, *calculate, *copy;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"RANDOM PASSWORD GENERATOR");
    gtk_container_set_border_width (GTK_CONTAINER (window), 50);
    gtk_window_set_default_size(GTK_WINDOW(window),500,400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    number1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number1, 0, 10, 1, 1);
    

    calculate = gtk_button_new_with_label("\n GO \n");
    g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
    gtk_grid_set_row_spacing (GTK_GRID(grid),50);
    gtk_widget_set_halign (grid, GTK_ALIGN_CENTER);
    gtk_grid_attach(GTK_GRID(grid), calculate, 0, 30, 3, 1);
    
                      

    show = gtk_label_new("\n\n Password: ");
    gtk_grid_attach(GTK_GRID(grid), show, 0, 40, 2, 1);
    gtk_widget_set_halign (grid, GTK_ALIGN_CENTER);
    gtk_grid_set_row_spacing (GTK_GRID(grid),50);
    
    
    copy = gtk_button_new_with_label("\n copy \n");
    g_signal_connect(copy, "clicked",G_CALLBACK(do_copy) , NULL);
    gtk_grid_set_row_spacing (GTK_GRID(grid),30);
    gtk_widget_set_halign (grid, GTK_ALIGN_CENTER);
    gtk_grid_attach(GTK_GRID(grid), copy, 0, 60, 4, 1);
    
    
    result = gtk_label_new(" ");
    gtk_grid_attach(GTK_GRID(grid), result, 0, 50, 2, 1);
    
    print = gtk_label_new(" ");
    gtk_grid_attach(GTK_GRID(grid), print, 0, 70, 4, 1);
    

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}


