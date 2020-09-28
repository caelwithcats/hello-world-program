#include <libwidget/Application.h>
#include <libwidget/Widgets.h>
#include <libwidget/dialog/Dialog.h>

int main(int argc, char **argv)
{
    application_initialize(argc, argv);

    // This is the main window
    Window *window = new Window(WINDOW_RESIZABLE);

    // The insets are the padding
    window->root()->insets(Insets(8));
    window->root()->layout(VFLOW(0));
    window->icon(Icon::get("application"));
    window->title("Hello World!");
    window->size(Vec2i(500, 400));

    // Create widgets
    new Label(window->root(), "Hello World!", Position::CENTER);
    auto button = new Button(window->root(), BUTTON_FILLED, "Click Me!");

    button->on(Event::ACTION, [](auto) {
         dialog_message(Icon::get("close"), "Hi", "You clicked me", DIALOG_BUTTON_OK);
    });
    window->show();

    return application_run();
}