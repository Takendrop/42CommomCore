#include "../../headers/minishell.h"

/*initializes program parameters and attributes using enviroment 
variables*/
void init_parmas(int ac, char **av, t_attr *att, char **envp)
{
    (void)ac;
    (void)av;
    init_attributes_one(att);
    init_attributes_two(att);
    start_env(envp, att);
    start_exp(envp, att);
}


/*sets initial value for the first group of attributes in 
the t_attr structure*/
void init_attributes_one(t_attr *att)
{
    att->nb_tokens = 0;
	att->index = 0;
	att->tok_arr = NULL;
	att->d_env = NULL;
	att->len_d_env = 0;
	att->d_exp_env = NULL;
	att->len_d_exp_env = 0;
	att->commands_arr = NULL;
	att->tok_arr_i = 0;
	att->pars_data.nb_tokenst = 0;
	att->pars_data.pars_arr = NULL;
	att->write_to_pipe = 0;
	att->read_from_pipe = 0;
	att->only_create = 0;
	att->first_flag = 0;
	att->already_dealt = 0;
	att->has_path = 1;
}

/*
initialixe the additional attirbutes in the t_attr structure focusing
on pipes and file handling setting
*/
void init_attributes_two(t_attr *att)
{
    att->number_of_pipes = 0;
	att->number_of_redir = 0;
	att->number_of_append = 0;
	att->number_of_read = 0;
	att->redir_fd = 0;
	att->redir = 0;
	att->create_file = 0;
	att->heredoc = 0;
	att->skip = 0;
	att->read_from_file = 0;
	att->pipeindex = 0;
	att->o_dquotes = 0;
	att->o_quotes = 0;
	att->aftert = NULL;
	att->inside_single_quotes = 0;
}


/*initialize t_toki structure*/
void init_toki(t_toki *tok)
{
    tok->i = 0;
    tok->j = 0;
    tok->pos = 0;
    tok->flag = 0;
    tok->token = NULL;
}

/*resets certain attributes in t_attr for reuse and ensure clean state
while preserving some env_related data*/
void reinit_att(t_attr *att)
{
    att->nb_tokens = 0;
	att->index = 0;
	att->tok_arr = NULL;
	att->tok_arr_i = 0;
	att->last_path = search_variables_in_env(att, "OLDPWD");
	att->pars_data.nb_tokenst = 0;
	att->number_of_pipes = 0;
	att->number_of_redir = 0;
	att->number_of_append = 0;
	att->pipeindex = 0;
	att->o_dquotes = 0;
	att->o_quotes = 0;
	att->aftert = NULL;
	att->already_dealt = 0;
	att->has_path = 1;
}