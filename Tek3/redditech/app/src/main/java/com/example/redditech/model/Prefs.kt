package com.example.redditech.model

data class Prefs (
    var beta: Boolean,
    var default_theme_sr: Boolean,
    var threaded_messages: Boolean,
    var email_comment_reply: Boolean,
    var private_feeds: Boolean,
    var activity_relevant_ads: Boolean,
    var email_messages: Boolean,
    var profile_opt_out: Boolean,
    var video_autoplay: Boolean,
    var email_private_message: Boolean,
    var geopopular: String,
    var show_link_flair: Boolean,
    var show_trending: Boolean,
    var send_welcome_messages: Boolean,
    var country_code: String,
    var design_beta: Boolean,
    var monitor_mentions: Boolean,
    var hide_downs: Boolean,
    var clickgadget: Boolean,
    var lang: String,
    var ignore_suggested_sort: Boolean,
    var show_presence: Boolean,
    var email_upvote_comment: Boolean,
    var email_digests: Boolean,
    var layout: Int,
    var num_comments: Int,
    var feed_recommendations_enabled: Boolean,
    var label_nsfw: Boolean,
    var research: Boolean,
    var use_global_defaults: Boolean,
    var show_snoovatar: Boolean,
    var over_18: Boolean,
    var legacy_search: Boolean,
    var live_orangereds: Boolean,
    var highlight_controversial: Boolean,
    var no_profanity: Boolean,
    var domain_details: Boolean,
    var collapse_left_bar: Boolean,
    var email_community_discovery: Boolean,
    var bad_comment_autocollapse: String,
    var hide_ups: Boolean,
    var third_party_data_personalized_ads: Boolean,
    var email_chat_request: Boolean,
    var allow_clicktracking: Boolean,
    var hide_from_robots: Boolean,
    var show_twitter: Boolean,
    var compress: Boolean,
    var accept_pms: String,
    var store_visits: Boolean,
    var threaded_modmail: Boolean,
    var email_upvote_post: Boolean,
    var min_link_score: Int,
    var media_preview: String,
    var email_user_new_follower: Boolean,
    var nightmode: Boolean,
    var enable_default_themes: Boolean,
    var third_party_site_data_personalized_content: Boolean,
    var third_party_site_data_personalized_ads: Boolean,
    var survey_last_seen_time: Int,
    var show_stylesheets: Boolean,
    var enable_followers: Boolean,
    var email_new_user_welcome: Boolean,
    var public_votes: Boolean,
    var email_post_reply: Boolean,
    var collapse_read_messages: Boolean,
    var show_flair: Boolean,
    var mark_messages_read: Boolean,
    var search_include_over_18: Boolean,
    var hide_ads: Boolean,
    var third_party_personalized_ads: Boolean,
    var email_username_mention: Boolean,
    var top_karma_subreddits: Boolean,
    var newwindow: Boolean,
    var numsites: Int,
    var min_comment_score: Int,
    var send_crosspost_messages: Boolean,
    var media: String,
    var public_server_seconds: Boolean,
    var show_gold_expiration: Boolean,
    var highlight_new_comments: Boolean,
    var email_unsubscribe_all: Boolean,
    var default_comment_sort: String,
    var show_location_based_recommendations: Boolean
)