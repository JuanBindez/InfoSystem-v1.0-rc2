#include <stdio.h>
#include <gtk/gtk.h>

void exibirTemperaturaSistema(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;

    FILE *cmd = popen("sensors", "r");
    if (cmd == NULL) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Erro ao obter a temperatura do sistema.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), cmd) != NULL) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", buffer);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy
