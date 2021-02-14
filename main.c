#include <stdio.h>
#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data)
{
    g_print("hello world\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget  *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    GtkButtonBox *buttonBox = (GtkButtonBox *) gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(window), (GtkWidget *) buttonBox);
    GtkButton *button = (GtkButton *) gtk_button_new_with_label("hello world");
    gtk_container_add(GTK_CONTAINER(buttonBox), (GtkWidget *) button);
    gtk_button_get_label(button);

    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_window_close), window);

    gtk_widget_show_all(window);
}

int main(int argc, char** argv)
{
    GtkApplication *app;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}