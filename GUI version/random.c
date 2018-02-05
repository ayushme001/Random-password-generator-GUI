#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gtk/gtk.h>

static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *result;
static GtkWidget *show;


void do_calculate(GtkWidget *calculate, gpointer data) {
    int n = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1)));
  
    int i = 0;
    
    char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/_.-+=<>?";
        srand(time(NULL));
      
        char c[n];
        char buffer[32];
        for(i = 0; i < n; i++)
        {  
            c[i] = a[rand() % (sizeof(a))];
            
          //  printf("%c", c[i]);  
        }

    

    gtk_label_set_text(GTK_LABEL(result), c);
}


//for compiling use - 
// gcc random.c -o random `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`




int main(int argc, char **argv) { 
    GtkWidget *window, *grid, *calculate;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"RANDOM PASSWORD GENERATOR");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window),200,400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    number1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number1, 0, 10, 1, 1);
    

    calculate = gtk_button_new_with_label("\n GO \n");
    g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
    gtk_grid_set_row_spacing (GTK_GRID(grid),50);
    gtk_grid_attach(GTK_GRID(grid), calculate, 0, 30, 3, 1);
    
                       
    

    show = gtk_label_new("\n\n Password: ");
    gtk_grid_attach(GTK_GRID(grid), show, 0, 40, 2, 1);
    gtk_grid_set_row_spacing (GTK_GRID(grid),50);
    
   
    
    result = gtk_label_new(" ");
    gtk_grid_attach(GTK_GRID(grid), result, 0, 50, 2, 1);
    

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}


