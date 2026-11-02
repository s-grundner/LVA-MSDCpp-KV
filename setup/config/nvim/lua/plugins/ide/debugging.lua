return {
  {
    "mfussenegger/nvim-dap",
    dependencies = {
      "rcarriga/nvim-dap-ui",
    },
  },
  {
    "mfussenegger/nvim-dap-python",
    ft = "python",
    dependencies = {
      "mfussenegger/nvim-dap",
    },
    config = function(_, opts)
      local path = "~/.local/share/nvim/mason/packages/debugpy/venv/python"
      require("dap-python").setup(path)
    end,
  },
  {
    "rcarriga/nvim-dap-ui",
    dependencies = {
      "mfussenegger/nvim-dap",
      "nvim-neotest/nvim-nio",
    },
    config = function()
      local dap = require("dap")
      local dapui = require("dapui")

      dapui.setup()

      dap.listeners.before.launch.dapui_config = function()
        dapui.open()
      end

      -- dap.listeners.after.event_initialized["dapui_config"] = function ()
      --     dapui.open()
      -- end
      -- dap.listeners.before.event_terminated["dapui_config"] = function ()
      --     dapui.close()
      -- end
      -- dap.listeners.before.event_exited["dapui_config"] = function ()
      --     dapui.close()
      -- end
      vim.keymap.set("n", "<leader>dt", dap.toggle_breakpoint, { desc = "[D]ebug [T]oggle Breakpoint" })
      vim.keymap.set("n", "<leader>ds", dap.continue, { desc = "[D]ebug [S]tart" })
      vim.keymap.set("n", "<leader>dc", dapui.close, { desc = "[D]ebug [C]lose" })
    end,
  },
}
