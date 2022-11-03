cmake_minimum_required(VERSION 3.15)
project(MyTeams)

set(CMAKE_C_STANDARD 11)

include_directories(includes libs/myteams)

add_executable(lists
        includes/linked_list.h
        src/server/lists/linked_list.c
        src/server/lists/find_by_uuid.c
        src/server/lists/find_by_name.c
        src/server/lists/remove.c
        src/server/lists/list_len.c
        src/server/lists/find_private_message.c)

add_executable(loader
        includes/loader.h
        src/server/loader/load_users.c
        src/server/loader/load_teams.c
        src/server/loader/load_threads.c
        src/server/loader/load_channel.c
        src/server/loader/load_privatemessages.c
        includes/utils.h)

add_executable(writer
        includes/writer.h
        src/server/writer/add_new.c
        src/server/writer/split_file.c
        src/server/writer/add_thread_reply.c
        src/server/writer/team_subscribe.c
        src/server/writer/channel_subscribe.c
        src/server/writer/add_to_upper.c
        src/server/writer/set_parent.c
        src/server/writer/team_unsubscribe.c
        src/server/writer/channel_unsubscribe.c
        src/server/writer/channel_subscribe.c
        src/server/writer/add_to_upper.c
        src/server/writer/set_parent.c
        src/server/writer/team_unsubscribe.c
        src/server/writer/channel_unsubscribe.c
        src/server/writer/free_buffer.c src/server/writer/update_var.c)

add_executable(server
        libs/myteams/logging_server.h
        includes/server.h
        includes/linked_list.h
        includes/client.h
        src/server/main.c
        src/server/server.c
        src/server/error.c
        src/server/init.c
        src/server/commands/login.c
        src/server/commands/logout.c
        src/server/commands/users.c
        src/server/commands/user.c
        src/server/commands/send.c
        src/server/commands/messages.c
        src/server/commands/subscribe.c
        src/server/commands/subscribed.c
        src/server/commands/unsubscribe.c
        src/server/commands/use.c
        src/server/commands/create.c
        src/server/commands/list.c
        src/server/list_error.c
        src/server/commands/info.c
        src/server/commands.c
        src/server/is_uuid.c
        src/server/lists/find_by_name.c
        src/server/lists/find_by_uuid.c
        src/server/lists/find_private_message.c
        src/server/lists/linked_list.c
        src/server/lists/list_len.c
        src/server/split_args.c
        src/server/lists/remove.c
        includes/utils.h
        src/server/utils.c
        src/server/create_file.c
        src/server/commands/create_thread.c
        src/server/commands/print_new_channel.c
        src/server/lists/remove.c
        includes/utils.h
        src/server/utils.c
        src/server/create_file.c
        src/server/commands/create_thread.c src/server/commands/create_channel.c src/server/commands/list_norme.c)

add_executable(client
        libs/myteams/logging_client.h
        includes/client.h
        src/client/main.c
        src/client/is_number.c
        src/client/handle_client.c
        src/client/init_connection.c
        src/client/get_line.c
        src/client/client.c
        src/client/split_string.c
        src/client/send_command.c
        src/client/read_command.c
        src/client/new_client.c
        src/client/char_to_time.c
        src/client/send_command_error.c
        src/client/send_logout.c
        src/client/commands/channel_print_threads.c
        src/client/commands/error_already_exist.c
        src/client/commands/error_unauthorized.c
        src/client/commands/error_unknown_channel.c
        src/client/commands/error_unknown_team.c
        src/client/commands/error_unknown_thread.c
        src/client/commands/error_unknown_user.c
        src/client/commands/event_channel_created.c
        src/client/commands/event_logged_in.c
        src/client/commands/event_logged_out.c
        src/client/commands/private_message_received.c
        src/client/commands/event_team_created.c
        src/client/commands/event_thread_created.c
        src/client/commands/thread_reply_received.c
        src/client/commands/print_channel_created.c
        src/client/commands/print_reply_created.c
        src/client/commands/print_subscribed.c
        src/client/commands/print_team_created.c
        src/client/commands/print_team.c
        src/client/commands/print_teams.c
        src/client/commands/print_thread_created.c
        src/client/commands/print_thread.c
        src/client/commands/print_unsubscribed.c
        src/client/commands/print_user.c
        src/client/commands/print_users.c
        src/client/commands/message_print_messages.c
        src/client/commands/team_print_channels.c
        src/client/commands/thread_print_replies.c
        src/client/commands/print_channel.c
        src/client/split_args.c src/client/commands/force_logout.c src/client/commands/logout.c)

add_executable(bonus
        bonus/close.c
        bonus/close_teams.c
        bonus/disconnect.c
        bonus/server_command.c)
