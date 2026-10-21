return {
  {
    "ThePrimeagen/harpoon",
    lazy = false,
    dependencies = {
      "nvim-lua/plenary.nvim",
    },
    config = true,
    keys = {
      { "<leader>ha", "<cmd>lua require('harpoon.mark').add_file()<cr>", desc = "Harpoon [a]dd file" },
      { "<leader>hn", "<cmd>lua require('harpoon.ui').nav_next()<cr>", desc = "Harpoon Go to [n]ext mark" },
      {
        "<leader>hp",
        "<cmd>lua require('harpoon.ui').nav_prev()<cr>",
        desc = "Harpoon Go to [p]revious mark",
      },
      { "<leader>hm", "<cmd>lua require('harpoon.ui').toggle_quick_menu()<cr>", desc = "Harpoon Show [m]arks" },
    },
  },
  {
    "nvim-telescope/telescope.nvim",
    dependencies = {
      "nvim-lua/plenary.nvim",
      "debugloop/telescope-undo.nvim",
    },
    config = function()
      require("telescope").setup({
        opts = {
          extensions = {
            undo = {
              use_delta = true,
              use_custom_command = nil,
              side_by_side = false,
              vim_diff_opts = {
                ctxlen = vim.o.scrolloff,
              },
              entry_format = "state #$ID, $STAT, $TIME",
              time_format = "",
              saved_only = false,
            },
          },
        },
      })
      require("telescope").load_extension("undo")
      vim.keymap.set("n", "<leader>fu", "<cmd>Telescope undo<cr>")
    end,
    lazy = false,
  },
  {
    "christoomey/vim-tmux-navigator",
    cmd = {
      "TmuxNavigateLeft",
      "TmuxNavigateDown",
      "TmuxNavigateUp",
      "TmuxNavigateRight",
      "TmuxNavigatePrevious",
      "TmuxNavigatorProcessList",
    },
    keys = {
      { "<c-h>", "<cmd><C-U>TmuxNavigateLeft<cr>" },
      { "<c-j>", "<cmd><C-U>TmuxNavigateDown<cr>" },
      { "<c-k>", "<cmd><C-U>TmuxNavigateUp<cr>" },
      { "<c-l>", "<cmd><C-U>TmuxNavigateRight<cr>" },
      { "<c-\\>", "<cmd><C-U>TmuxNavigatePrevious<cr>" },
    },
    lazy = false,
  },
}
